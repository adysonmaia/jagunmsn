#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    socket = new JagunKET(this);
    connected = false;
    connect(ui->btnConexao,SIGNAL(clicked()),this,SLOT(controlConnection()));
    connect(socket,SIGNAL(connected()),this,SLOT(connectedServer()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnectServer()));
    connect(socket,SIGNAL(sentData()),this,SLOT(confirmSend()));
    connect(ui->btnEnviar,SIGNAL(clicked()),this,SLOT(sendData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::controlConnection()
{
    if(!connected)
    {
        ui->btnConexao->setEnabled(false);
        ui->txtEntrada->setEnabled(false);
        ui->btnEnviar->setEnabled(false);
        socket->connectToHost(QHostAddress::LocalHost,9999);
    }
    else
    {
        ui->btnConexao->setEnabled(false);
        ui->txtEntrada->setEnabled(false);
        ui->btnEnviar->setEnabled(false);
        socket->close();
    }
}

void MainWindow::connectedServer()
{
    connected = true;
    ui->btnConexao->setText(tr("Desconectar"));
    ui->btnConexao->setEnabled(true);
    ui->txtEntrada->setEnabled(true);
    ui->btnEnviar->setEnabled(true);
}

void MainWindow::disconnectServer()
{
    connected = false;
    ui->txtEntrada->clear();
    ui->btnConexao->setText(tr("Conectar"));
    ui->btnConexao->setEnabled(true);
    ui->txtEntrada->setEnabled(false);
    ui->btnEnviar->setEnabled(false);
}

void MainWindow::sendData()
{
    ui->txtEntrada->setEnabled(false);
    ui->btnEnviar->setEnabled(false);
    QString data = ui->txtEntrada->text();
    QByteArray byteData;
    byteData.append(data);
    socket->send(&byteData);

}

void MainWindow::confirmSend()
{
    ui->txtEntrada->clear();
    ui->txtEntrada->setEnabled(true);
    ui->btnEnviar->setEnabled(true);
    QMessageBox::warning(this,tr("Destinatario recebeu dado"),tr("Destinatario recebeu dado"));
}

