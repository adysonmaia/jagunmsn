/********************************************************************************
** Form generated from reading ui file 'jagunchatwindow.ui'
**
** Created: Sun May 31 19:43:32 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JAGUNCHATWINDOW_H
#define UI_JAGUNCHATWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "jagunchatlistusers.h"

QT_BEGIN_NAMESPACE

class Ui_JagunChatWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    JagunChatListUsers *lwUsers;
    QTextBrowser *tbChat;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbUser;
    QTextEdit *teMessageUser;
    QPushButton *btnSendMessage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JagunChatWindow)
    {
        if (JagunChatWindow->objectName().isEmpty())
            JagunChatWindow->setObjectName(QString::fromUtf8("JagunChatWindow"));
        JagunChatWindow->resize(640, 480);
        JagunChatWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(JagunChatWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lwUsers = new JagunChatListUsers(centralwidget);
        lwUsers->setObjectName(QString::fromUtf8("lwUsers"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lwUsers->sizePolicy().hasHeightForWidth());
        lwUsers->setSizePolicy(sizePolicy);
        lwUsers->setMinimumSize(QSize(88, 0));
        lwUsers->setMaximumSize(QSize(88, 16777215));
        lwUsers->setFocusPolicy(Qt::NoFocus);
        lwUsers->setLayoutDirection(Qt::LeftToRight);
        lwUsers->setAutoFillBackground(false);
        lwUsers->setFrameShape(QFrame::NoFrame);
        lwUsers->setFrameShadow(QFrame::Plain);
        lwUsers->setLineWidth(0);
        lwUsers->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lwUsers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lwUsers->setProperty("showDropIndicator", QVariant(false));
        lwUsers->setSelectionMode(QAbstractItemView::NoSelection);

        horizontalLayout->addWidget(lwUsers);

        tbChat = new QTextBrowser(centralwidget);
        tbChat->setObjectName(QString::fromUtf8("tbChat"));

        horizontalLayout->addWidget(tbChat);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbUser = new QLabel(centralwidget);
        lbUser->setObjectName(QString::fromUtf8("lbUser"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbUser->sizePolicy().hasHeightForWidth());
        lbUser->setSizePolicy(sizePolicy1);
        lbUser->setMinimumSize(QSize(88, 80));
        lbUser->setMaximumSize(QSize(88, 80));
        lbUser->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbUser);

        teMessageUser = new QTextEdit(centralwidget);
        teMessageUser->setObjectName(QString::fromUtf8("teMessageUser"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(teMessageUser->sizePolicy().hasHeightForWidth());
        teMessageUser->setSizePolicy(sizePolicy2);
        teMessageUser->setMinimumSize(QSize(0, 80));
        teMessageUser->setMaximumSize(QSize(16777215, 80));
        teMessageUser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        teMessageUser->setUndoRedoEnabled(false);
        teMessageUser->setAcceptRichText(false);

        horizontalLayout_2->addWidget(teMessageUser);

        btnSendMessage = new QPushButton(centralwidget);
        btnSendMessage->setObjectName(QString::fromUtf8("btnSendMessage"));
        btnSendMessage->setMinimumSize(QSize(1, 80));

        horizontalLayout_2->addWidget(btnSendMessage);


        verticalLayout->addLayout(horizontalLayout_2);

        JagunChatWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JagunChatWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        JagunChatWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(JagunChatWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        JagunChatWindow->setStatusBar(statusbar);

        retranslateUi(JagunChatWindow);

        QMetaObject::connectSlotsByName(JagunChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *JagunChatWindow)
    {
        JagunChatWindow->setWindowTitle(QApplication::translate("JagunChatWindow", "Jagun Chat", 0, QApplication::UnicodeUTF8));
        JagunChatWindow->setStyleSheet(QApplication::translate("JagunChatWindow", "QMainWindow#JagunChatWindow\n"
"{\n"
"	background-color: white;\n"
"}", 0, QApplication::UnicodeUTF8));
        lbUser->setText(QApplication::translate("JagunChatWindow", "User Img", 0, QApplication::UnicodeUTF8));
        btnSendMessage->setText(QApplication::translate("JagunChatWindow", "Enviar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(JagunChatWindow);
    } // retranslateUi

};

namespace Ui {
    class JagunChatWindow: public Ui_JagunChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAGUNCHATWINDOW_H
