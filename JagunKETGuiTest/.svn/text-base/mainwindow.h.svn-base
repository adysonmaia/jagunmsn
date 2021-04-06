#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "jagunket.h"

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    JagunKET *socket;
    Ui::MainWindowClass *ui;
    bool connected;
private slots:
    void controlConnection();
    void connectedServer();
    void sendData();
    void confirmSend();
    void disconnectServer();
};

#endif // MAINWINDOW_H
