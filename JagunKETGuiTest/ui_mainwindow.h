/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sat 18. Apr 11:15:46 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *txtEntrada;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConexao;
    QPushButton *btnEnviar;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(176, 124);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowClass->sizePolicy().hasHeightForWidth());
        MainWindowClass->setSizePolicy(sizePolicy);
        MainWindowClass->setMinimumSize(QSize(176, 124));
        MainWindowClass->setMaximumSize(QSize(176, 124));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtEntrada = new QLineEdit(centralWidget);
        txtEntrada->setObjectName(QString::fromUtf8("txtEntrada"));
        txtEntrada->setEnabled(false);

        verticalLayout->addWidget(txtEntrada);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnConexao = new QPushButton(centralWidget);
        btnConexao->setObjectName(QString::fromUtf8("btnConexao"));

        horizontalLayout->addWidget(btnConexao);

        btnEnviar = new QPushButton(centralWidget);
        btnEnviar->setObjectName(QString::fromUtf8("btnEnviar"));
        btnEnviar->setEnabled(false);

        horizontalLayout->addWidget(btnEnviar);


        verticalLayout->addLayout(horizontalLayout);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 176, 22));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        QWidget::setTabOrder(txtEntrada, btnConexao);
        QWidget::setTabOrder(btnConexao, btnEnviar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnConexao->setText(QApplication::translate("MainWindowClass", "Conectar", 0, QApplication::UnicodeUTF8));
        btnEnviar->setText(QApplication::translate("MainWindowClass", "Enviar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindowClass);
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
