/********************************************************************************
** Form generated from reading ui file 'jagunwindow.ui'
**
** Created: Sun May 31 19:43:32 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JAGUNWINDOW_H
#define UI_JAGUNWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "jagunlistusers.h"

QT_BEGIN_NAMESPACE

class Ui_JagunWindow
{
public:
    QAction *actConfig;
    QAction *actHelp;
    QAction *actStatusAvailable;
    QAction *actStatusBusy;
    QAction *actStatusAway;
    QAction *actStatusInvisible;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbJagunImage;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStatusUser;
    QLineEdit *leExibitionNameUser;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leMsgUser;
    QPushButton *btnImageUser;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidgetMain;
    QWidget *swmLogin;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QLineEdit *leLoginUser;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QLineEdit *lePasswordUser;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *chbRememberPassword;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnEnter;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnNewUser;
    QPushButton *btnForgotPassword;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QWidget *swmNewUser;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_21;
    QLabel *lbErrorEmailNewUser;
    QLabel *label_6;
    QLineEdit *leEmailNewUser;
    QVBoxLayout *verticalLayout_16;
    QLabel *lbErrorLoginNewUser;
    QLabel *label_3;
    QLineEdit *leLoginNewUser;
    QVBoxLayout *verticalLayout_17;
    QLabel *lbErrorPasswordNewUser;
    QLabel *label_4;
    QLineEdit *lePasswordNewUser;
    QVBoxLayout *verticalLayout_20;
    QLabel *lbErrorConfirmPasswordNewUser;
    QLabel *label_5;
    QLineEdit *leConfirmPasswordNewUser;
    QVBoxLayout *verticalLayout_18;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btnRegisterNewUser;
    QPushButton *btnCancelNewUser;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_8;
    QWidget *swmConnected;
    QVBoxLayout *verticalLayout_22;
    QLineEdit *leSearchUser;
    JagunListUsers *lwUsers;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btnAddUser;
    QPushButton *btnFilterUser;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QStatusBar *sbStatusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *JagunWindow)
    {
        if (JagunWindow->objectName().isEmpty())
            JagunWindow->setObjectName(QString::fromUtf8("JagunWindow"));
        JagunWindow->setEnabled(true);
        JagunWindow->resize(308, 589);
        JagunWindow->setMouseTracking(true);
        JagunWindow->setAutoFillBackground(false);
        JagunWindow->setDocumentMode(false);
        actConfig = new QAction(JagunWindow);
        actConfig->setObjectName(QString::fromUtf8("actConfig"));
        QFont font;
        font.setUnderline(true);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::NoAntialias);
        actConfig->setFont(font);
        actConfig->setAutoRepeat(false);
        actConfig->setVisible(true);
        actConfig->setIconVisibleInMenu(false);
        actHelp = new QAction(JagunWindow);
        actHelp->setObjectName(QString::fromUtf8("actHelp"));
        QFont font1;
        font1.setUnderline(true);
        actHelp->setFont(font1);
        actStatusAvailable = new QAction(JagunWindow);
        actStatusAvailable->setObjectName(QString::fromUtf8("actStatusAvailable"));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/icons/1")), QIcon::Normal, QIcon::Off);
        actStatusAvailable->setIcon(icon);
        actStatusAvailable->setProperty("statusType", QVariant(1u));
        actStatusBusy = new QAction(JagunWindow);
        actStatusBusy->setObjectName(QString::fromUtf8("actStatusBusy"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/icons/2")), QIcon::Normal, QIcon::Off);
        actStatusBusy->setIcon(icon1);
        actStatusBusy->setProperty("statusType", QVariant(2u));
        actStatusAway = new QAction(JagunWindow);
        actStatusAway->setObjectName(QString::fromUtf8("actStatusAway"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/icons/3")), QIcon::Normal, QIcon::Off);
        actStatusAway->setIcon(icon2);
        actStatusAway->setProperty("statusType", QVariant(3u));
        actStatusInvisible = new QAction(JagunWindow);
        actStatusInvisible->setObjectName(QString::fromUtf8("actStatusInvisible"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/icons/resource/offlineIcon.png")), QIcon::Normal, QIcon::Off);
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/icons/0")), QIcon::Normal, QIcon::On);
        actStatusInvisible->setIcon(icon3);
        actStatusInvisible->setProperty("statusType", QVariant(0u));
        centralWidget = new QWidget(JagunWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, -1, -1, 3);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 6);
        lbJagunImage = new QLabel(centralWidget);
        lbJagunImage->setObjectName(QString::fromUtf8("lbJagunImage"));
        lbJagunImage->setMinimumSize(QSize(167, 80));
        lbJagunImage->setMaximumSize(QSize(80, 167));
        lbJagunImage->setAutoFillBackground(true);
        lbJagunImage->setTextFormat(Qt::PlainText);
        lbJagunImage->setAlignment(Qt::AlignCenter);
        lbJagunImage->setWordWrap(false);

        verticalLayout->addWidget(lbJagunImage);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnStatusUser = new QPushButton(centralWidget);
        btnStatusUser->setObjectName(QString::fromUtf8("btnStatusUser"));
        btnStatusUser->setEnabled(false);
        btnStatusUser->setMinimumSize(QSize(35, 20));
        btnStatusUser->setMaximumSize(QSize(20, 20));
        btnStatusUser->setAutoFillBackground(false);
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/icons/0")), QIcon::Normal, QIcon::Off);
        btnStatusUser->setIcon(icon4);
        btnStatusUser->setFlat(true);

        horizontalLayout->addWidget(btnStatusUser);

        leExibitionNameUser = new QLineEdit(centralWidget);
        leExibitionNameUser->setObjectName(QString::fromUtf8("leExibitionNameUser"));
        leExibitionNameUser->setEnabled(false);

        horizontalLayout->addWidget(leExibitionNameUser);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(41, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        leMsgUser = new QLineEdit(centralWidget);
        leMsgUser->setObjectName(QString::fromUtf8("leMsgUser"));
        leMsgUser->setEnabled(false);

        horizontalLayout_3->addWidget(leMsgUser);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        btnImageUser = new QPushButton(centralWidget);
        btnImageUser->setObjectName(QString::fromUtf8("btnImageUser"));
        btnImageUser->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnImageUser->sizePolicy().hasHeightForWidth());
        btnImageUser->setSizePolicy(sizePolicy);
        btnImageUser->setMinimumSize(QSize(85, 80));
        btnImageUser->setFocusPolicy(Qt::NoFocus);
        btnImageUser->setIconSize(QSize(80, 80));
        btnImageUser->setFlat(true);

        horizontalLayout_2->addWidget(btnImageUser);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        stackedWidgetMain = new QStackedWidget(centralWidget);
        stackedWidgetMain->setObjectName(QString::fromUtf8("stackedWidgetMain"));
        stackedWidgetMain->setFrameShape(QFrame::NoFrame);
        stackedWidgetMain->setLineWidth(0);
        swmLogin = new QWidget();
        swmLogin->setObjectName(QString::fromUtf8("swmLogin"));
        verticalLayout_6 = new QVBoxLayout(swmLogin);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setMargin(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(swmLogin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setMargin(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_5 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(10);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(2);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(46, 14));
        QFont font2;
        font2.setPointSize(10);
        label->setFont(font2);

        verticalLayout_8->addWidget(label);

        leLoginUser = new QLineEdit(groupBox);
        leLoginUser->setObjectName(QString::fromUtf8("leLoginUser"));
        sizePolicy.setHeightForWidth(leLoginUser->sizePolicy().hasHeightForWidth());
        leLoginUser->setSizePolicy(sizePolicy);
        leLoginUser->setMinimumSize(QSize(180, 25));
        leLoginUser->setMaxLength(255);

        verticalLayout_8->addWidget(leLoginUser);


        verticalLayout_10->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font2);

        verticalLayout_7->addWidget(label_2);

        lePasswordUser = new QLineEdit(groupBox);
        lePasswordUser->setObjectName(QString::fromUtf8("lePasswordUser"));
        sizePolicy.setHeightForWidth(lePasswordUser->sizePolicy().hasHeightForWidth());
        lePasswordUser->setSizePolicy(sizePolicy);
        lePasswordUser->setMinimumSize(QSize(180, 25));
        lePasswordUser->setMaxLength(255);
        lePasswordUser->setEchoMode(QLineEdit::Password);

        verticalLayout_7->addWidget(lePasswordUser);


        verticalLayout_10->addLayout(verticalLayout_7);


        verticalLayout_11->addLayout(verticalLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        chbRememberPassword = new QCheckBox(groupBox);
        chbRememberPassword->setObjectName(QString::fromUtf8("chbRememberPassword"));
        chbRememberPassword->setFont(font2);
        chbRememberPassword->setIconSize(QSize(16, 16));

        horizontalLayout_4->addWidget(chbRememberPassword);


        verticalLayout_11->addLayout(horizontalLayout_4);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnEnter = new QPushButton(groupBox);
        btnEnter->setObjectName(QString::fromUtf8("btnEnter"));
        sizePolicy.setHeightForWidth(btnEnter->sizePolicy().hasHeightForWidth());
        btnEnter->setSizePolicy(sizePolicy);
        btnEnter->setMinimumSize(QSize(85, 23));
        btnEnter->setMaximumSize(QSize(101, 23));
        btnEnter->setFont(font2);
        btnEnter->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(btnEnter);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_3);

        btnNewUser = new QPushButton(groupBox);
        btnNewUser->setObjectName(QString::fromUtf8("btnNewUser"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        btnNewUser->setFont(font3);
        btnNewUser->setFlat(true);

        verticalLayout_9->addWidget(btnNewUser);

        btnForgotPassword = new QPushButton(groupBox);
        btnForgotPassword->setObjectName(QString::fromUtf8("btnForgotPassword"));
        btnForgotPassword->setFont(font3);
        btnForgotPassword->setFlat(true);

        verticalLayout_9->addWidget(btnForgotPassword);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);


        verticalLayout_4->addLayout(verticalLayout_9);


        verticalLayout_12->addLayout(verticalLayout_4);

        verticalLayout_12->setStretch(0, 1);

        verticalLayout_11->addLayout(verticalLayout_12);


        horizontalLayout_6->addLayout(verticalLayout_11);

        horizontalSpacer_6 = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_6->addWidget(groupBox);

        stackedWidgetMain->addWidget(swmLogin);
        swmNewUser = new QWidget();
        swmNewUser->setObjectName(QString::fromUtf8("swmNewUser"));
        verticalLayout_13 = new QVBoxLayout(swmNewUser);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setMargin(0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        groupBox_3 = new QGroupBox(swmNewUser);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setMargin(11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 9, -1, -1);
        horizontalSpacer_7 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setSizeConstraint(QLayout::SetFixedSize);
        lbErrorEmailNewUser = new QLabel(groupBox_3);
        lbErrorEmailNewUser->setObjectName(QString::fromUtf8("lbErrorEmailNewUser"));
        lbErrorEmailNewUser->setAutoFillBackground(false);

        verticalLayout_21->addWidget(lbErrorEmailNewUser);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font2);

        verticalLayout_21->addWidget(label_6);

        leEmailNewUser = new QLineEdit(groupBox_3);
        leEmailNewUser->setObjectName(QString::fromUtf8("leEmailNewUser"));
        sizePolicy.setHeightForWidth(leEmailNewUser->sizePolicy().hasHeightForWidth());
        leEmailNewUser->setSizePolicy(sizePolicy);
        leEmailNewUser->setMinimumSize(QSize(180, 25));
        leEmailNewUser->setMaxLength(255);
        leEmailNewUser->setEchoMode(QLineEdit::Normal);

        verticalLayout_21->addWidget(leEmailNewUser);


        verticalLayout_14->addLayout(verticalLayout_21);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        lbErrorLoginNewUser = new QLabel(groupBox_3);
        lbErrorLoginNewUser->setObjectName(QString::fromUtf8("lbErrorLoginNewUser"));

        verticalLayout_16->addWidget(lbErrorLoginNewUser);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(46, 14));
        label_3->setFont(font2);

        verticalLayout_16->addWidget(label_3);

        leLoginNewUser = new QLineEdit(groupBox_3);
        leLoginNewUser->setObjectName(QString::fromUtf8("leLoginNewUser"));
        sizePolicy.setHeightForWidth(leLoginNewUser->sizePolicy().hasHeightForWidth());
        leLoginNewUser->setSizePolicy(sizePolicy);
        leLoginNewUser->setMinimumSize(QSize(180, 25));
        leLoginNewUser->setMaxLength(255);

        verticalLayout_16->addWidget(leLoginNewUser);


        verticalLayout_14->addLayout(verticalLayout_16);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setSizeConstraint(QLayout::SetFixedSize);
        lbErrorPasswordNewUser = new QLabel(groupBox_3);
        lbErrorPasswordNewUser->setObjectName(QString::fromUtf8("lbErrorPasswordNewUser"));

        verticalLayout_17->addWidget(lbErrorPasswordNewUser);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font2);

        verticalLayout_17->addWidget(label_4);

        lePasswordNewUser = new QLineEdit(groupBox_3);
        lePasswordNewUser->setObjectName(QString::fromUtf8("lePasswordNewUser"));
        sizePolicy.setHeightForWidth(lePasswordNewUser->sizePolicy().hasHeightForWidth());
        lePasswordNewUser->setSizePolicy(sizePolicy);
        lePasswordNewUser->setMinimumSize(QSize(180, 25));
        lePasswordNewUser->setMaxLength(255);
        lePasswordNewUser->setEchoMode(QLineEdit::Password);

        verticalLayout_17->addWidget(lePasswordNewUser);


        verticalLayout_14->addLayout(verticalLayout_17);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        verticalLayout_20->setSizeConstraint(QLayout::SetFixedSize);
        lbErrorConfirmPasswordNewUser = new QLabel(groupBox_3);
        lbErrorConfirmPasswordNewUser->setObjectName(QString::fromUtf8("lbErrorConfirmPasswordNewUser"));

        verticalLayout_20->addWidget(lbErrorConfirmPasswordNewUser);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font2);

        verticalLayout_20->addWidget(label_5);

        leConfirmPasswordNewUser = new QLineEdit(groupBox_3);
        leConfirmPasswordNewUser->setObjectName(QString::fromUtf8("leConfirmPasswordNewUser"));
        sizePolicy.setHeightForWidth(leConfirmPasswordNewUser->sizePolicy().hasHeightForWidth());
        leConfirmPasswordNewUser->setSizePolicy(sizePolicy);
        leConfirmPasswordNewUser->setMinimumSize(QSize(180, 25));
        leConfirmPasswordNewUser->setMaxLength(255);
        leConfirmPasswordNewUser->setEchoMode(QLineEdit::Password);

        verticalLayout_20->addWidget(leConfirmPasswordNewUser);


        verticalLayout_14->addLayout(verticalLayout_20);


        verticalLayout_15->addLayout(verticalLayout_14);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(0);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        btnRegisterNewUser = new QPushButton(groupBox_3);
        btnRegisterNewUser->setObjectName(QString::fromUtf8("btnRegisterNewUser"));
        sizePolicy.setHeightForWidth(btnRegisterNewUser->sizePolicy().hasHeightForWidth());
        btnRegisterNewUser->setSizePolicy(sizePolicy);
        btnRegisterNewUser->setMinimumSize(QSize(85, 23));
        btnRegisterNewUser->setMaximumSize(QSize(101, 23));
        btnRegisterNewUser->setFont(font2);
        btnRegisterNewUser->setLayoutDirection(Qt::LeftToRight);
        btnRegisterNewUser->setFlat(false);

        horizontalLayout_9->addWidget(btnRegisterNewUser);

        btnCancelNewUser = new QPushButton(groupBox_3);
        btnCancelNewUser->setObjectName(QString::fromUtf8("btnCancelNewUser"));
        sizePolicy.setHeightForWidth(btnCancelNewUser->sizePolicy().hasHeightForWidth());
        btnCancelNewUser->setSizePolicy(sizePolicy);
        btnCancelNewUser->setMinimumSize(QSize(85, 23));
        btnCancelNewUser->setMaximumSize(QSize(101, 23));
        btnCancelNewUser->setFont(font2);

        horizontalLayout_9->addWidget(btnCancelNewUser);


        verticalLayout_19->addLayout(horizontalLayout_9);


        verticalLayout_18->addLayout(verticalLayout_19);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_6);

        verticalLayout_18->setStretch(0, 1);

        verticalLayout_15->addLayout(verticalLayout_18);


        horizontalLayout_7->addLayout(verticalLayout_15);

        horizontalSpacer_8 = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout_13->addWidget(groupBox_3);

        stackedWidgetMain->addWidget(swmNewUser);
        swmConnected = new QWidget();
        swmConnected->setObjectName(QString::fromUtf8("swmConnected"));
        verticalLayout_22 = new QVBoxLayout(swmConnected);
        verticalLayout_22->setSpacing(3);
        verticalLayout_22->setMargin(0);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        leSearchUser = new QLineEdit(swmConnected);
        leSearchUser->setObjectName(QString::fromUtf8("leSearchUser"));
        leSearchUser->setMinimumSize(QSize(0, 25));
        leSearchUser->setMaximumSize(QSize(16777215, 30));
        leSearchUser->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_22->addWidget(leSearchUser);

        lwUsers = new JagunListUsers(swmConnected);
        lwUsers->setObjectName(QString::fromUtf8("lwUsers"));
        lwUsers->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lwUsers->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_22->addWidget(lwUsers);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        btnAddUser = new QPushButton(swmConnected);
        btnAddUser->setObjectName(QString::fromUtf8("btnAddUser"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        btnAddUser->setFont(font4);
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/general/resource/general/add.png")), QIcon::Normal, QIcon::Off);
        btnAddUser->setIcon(icon5);

        horizontalLayout_8->addWidget(btnAddUser);

        btnFilterUser = new QPushButton(swmConnected);
        btnFilterUser->setObjectName(QString::fromUtf8("btnFilterUser"));

        horizontalLayout_8->addWidget(btnFilterUser);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_22->addLayout(horizontalLayout_8);

        stackedWidgetMain->addWidget(swmConnected);

        verticalLayout_2->addWidget(stackedWidgetMain);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        JagunWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(JagunWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 308, 22));
        JagunWindow->setMenuBar(menuBar);
        sbStatusBar = new QStatusBar(JagunWindow);
        sbStatusBar->setObjectName(QString::fromUtf8("sbStatusBar"));
        JagunWindow->setStatusBar(sbStatusBar);
        toolBar = new QToolBar(JagunWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setWindowTitle(QString::fromUtf8("toolBar"));
#ifndef QT_NO_TOOLTIP
        toolBar->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
        toolBar->setLayoutDirection(Qt::RightToLeft);
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::TopToolBarArea);
        toolBar->setFloatable(false);
        JagunWindow->addToolBar(Qt::TopToolBarArea, toolBar);
#ifndef QT_NO_SHORTCUT
        label_6->setBuddy(lePasswordUser);
        label_3->setBuddy(leLoginUser);
        label_4->setBuddy(lePasswordUser);
        label_5->setBuddy(lePasswordUser);
#endif // QT_NO_SHORTCUT

        toolBar->addAction(actHelp);
        toolBar->addSeparator();
        toolBar->addAction(actConfig);

        retranslateUi(JagunWindow);

        stackedWidgetMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(JagunWindow);
    } // setupUi

    void retranslateUi(QMainWindow *JagunWindow)
    {
        JagunWindow->setWindowTitle(QApplication::translate("JagunWindow", "Jagun MSN", 0, QApplication::UnicodeUTF8));
        JagunWindow->setStyleSheet(QApplication::translate("JagunWindow", "QMainWindow\n"
"{\n"
"	background-color: #cdd0d7/*#c3c3dd;/*rgb(230, 231, 244);*/\n"
"}\n"
"\n"
"QLabel#lbErrorEmailNewUser\n"
"{\n"
"	color: red;\n"
"}\n"
"\n"
"QLabel#lbErrorLoginNewUser\n"
"{\n"
"	color: red;\n"
"}\n"
"\n"
"QLabel#lbErrorPasswordNewUser\n"
"{\n"
"	color: red;\n"
"}\n"
"\n"
"QLabel#lbErrorConfirmPasswordNewUser\n"
"{\n"
"	color: red;\n"
"\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"   border-width: 2px;\n"
"   border-style: solid;\n"
"   border-radius: 4px;\n"
"   border-color: rgb(106, 106, 106);/*black;/*rgb(212,223,233);*/\n"
"   padding-left: 5px;\n"
"   background-color: rgb(250, 247, 230);\n"
"   min-height: 21px;\n"
"}\n"
"\n"
"QLineEdit#leSearchUser\n"
"{\n"
"   padding-left: 22px;\n"
"   background-image: url(:/general/resource/general/search.png);\n"
"   background-repeat: no-repeat;\n"
"   background-position: center left;\n"
"   background-origin: padding;\n"
"   background-clip: padding;\n"
"}\n"
"\n"
"QLineEdit:disabled\n"
"{\n"
"	border-color: rgb(198, 198, 198);\n"
"	background-color:"
                        " rgb(236, 233, 216)\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	text-align: center center;\n"
"	border-color: rgb(106, 106, 106);/*rgb(0, 124, 195);*/\n"
"    padding: 4px;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-radius: 4px;\n"
"    min-width: 75px;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(236, 233, 216, 255), stop:0.1875 rgba(255, 255, 255, 255), stop:0.755682 rgba(255, 255, 255, 255), stop:1 rgba(236, 233, 216, 255));\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(190, 188, 176, 255), stop:0.255682 rgba(255, 255, 255, 255), stop:0.698864 rgba(255, 255, 255, 255), stop:1 rgba(190, 188, 176, 255));\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(172, 214, 220, 255), stop:0.0454545 rgba(226, 226, 226, 255), stop:0.926136 rgba(217, 217, 217, 255), stop:1 rgba(118, 195, 205, 255));\n"
""
                        "}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.0454545 rgba(233, 233, 216, 255), stop:0.914773 rgba(236, 233, 216, 255));\n"
"}\n"
"\n"
"QPushButton#btnStatusUser\n"
"{\n"
"  min-width: 25px;\n"
"}\n"
"\n"
"QListWidget\n"
"{\n"
"   background-color: rgb(244, 244, 244);/*rgb(231, 231, 231);*/\n"
"   border-width: 2px;\n"
"   border-style: solid;\n"
"   border-radius: 4px;\n"
"   border-color: rgb(106, 106, 106);/*rgb(212,223,233);*/\n"
"}\n"
"\n"
"QListWidget:disabled\n"
"{\n"
"	border-color: rgb(198, 198, 198);\n"
"	background-color: rgb(236, 233, 216)\n"
"}", 0, QApplication::UnicodeUTF8));
        actConfig->setText(QApplication::translate("JagunWindow", "Configura\303\247\303\265es", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actConfig->setToolTip(QApplication::translate("JagunWindow", "Configura\303\247\303\265es", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actHelp->setText(QApplication::translate("JagunWindow", "Ajuda", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actHelp->setToolTip(QApplication::translate("JagunWindow", "Ajuda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actStatusAvailable->setText(QApplication::translate("JagunWindow", "Disponivel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actStatusAvailable->setToolTip(QApplication::translate("JagunWindow", "Disponivel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actStatusBusy->setText(QApplication::translate("JagunWindow", "Ocupado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actStatusBusy->setToolTip(QApplication::translate("JagunWindow", "Ocupado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actStatusAway->setText(QApplication::translate("JagunWindow", "Ausente", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actStatusAway->setToolTip(QApplication::translate("JagunWindow", "Ausente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actStatusInvisible->setText(QApplication::translate("JagunWindow", "Offline", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actStatusInvisible->setToolTip(QApplication::translate("JagunWindow", "Offline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lbJagunImage->setText(QString());
        btnStatusUser->setText(QString());
        groupBox->setTitle(QApplication::translate("JagunWindow", "Login", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JagunWindow", "Nome de usu\303\241rio:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JagunWindow", "Senha:", 0, QApplication::UnicodeUTF8));
        chbRememberPassword->setText(QApplication::translate("JagunWindow", "Lembrar Senha", 0, QApplication::UnicodeUTF8));
        btnEnter->setText(QApplication::translate("JagunWindow", "Entrar", 0, QApplication::UnicodeUTF8));
        btnNewUser->setText(QApplication::translate("JagunWindow", "Novo Usu\303\241rio?", 0, QApplication::UnicodeUTF8));
        btnForgotPassword->setText(QApplication::translate("JagunWindow", "Esqueceu a Senha?", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("JagunWindow", "Novo Usu\303\241rio", 0, QApplication::UnicodeUTF8));
        lbErrorEmailNewUser->setText(QApplication::translate("JagunWindow", "Email inv\303\241lido", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("JagunWindow", "Email:", 0, QApplication::UnicodeUTF8));
        lbErrorLoginNewUser->setText(QApplication::translate("JagunWindow", "Usu\303\241rio inv\303\241lido", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("JagunWindow", "Nome de usu\303\241rio:", 0, QApplication::UnicodeUTF8));
        lbErrorPasswordNewUser->setText(QApplication::translate("JagunWindow", "Senha inv\303\241lida", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("JagunWindow", "Senha:", 0, QApplication::UnicodeUTF8));
        lbErrorConfirmPasswordNewUser->setText(QApplication::translate("JagunWindow", "Confirma\303\247\303\243o de senha n\303\243o confere", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("JagunWindow", "Confirmar Senha:", 0, QApplication::UnicodeUTF8));
        btnRegisterNewUser->setText(QApplication::translate("JagunWindow", "Cadastrar", 0, QApplication::UnicodeUTF8));
        btnCancelNewUser->setText(QApplication::translate("JagunWindow", "Cancelar", 0, QApplication::UnicodeUTF8));
        btnAddUser->setText(QApplication::translate("JagunWindow", "Adicionar", 0, QApplication::UnicodeUTF8));
        btnFilterUser->setText(QApplication::translate("JagunWindow", "Visualizar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JagunWindow: public Ui_JagunWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAGUNWINDOW_H
