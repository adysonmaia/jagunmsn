/********************************************************************************
** Form generated from reading ui file 'jagunuseritem.ui'
**
** Created: Sat May 2 21:17:55 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JAGUNUSERITEM_H
#define UI_JAGUNUSERITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JagunUserItem
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbUserStatus;
    QLabel *lbUserName;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *lbUserMessage;
    QLabel *lbUserImage;
    QFrame *line;

    void setupUi(QWidget *JagunUserItem)
    {
        if (JagunUserItem->objectName().isEmpty())
            JagunUserItem->setObjectName(QString::fromUtf8("JagunUserItem"));
        JagunUserItem->resize(320, 61);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JagunUserItem->sizePolicy().hasHeightForWidth());
        JagunUserItem->setSizePolicy(sizePolicy);
        JagunUserItem->setMinimumSize(QSize(0, 61));
        JagunUserItem->setMaximumSize(QSize(16777215, 61));
        JagunUserItem->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(JagunUserItem);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 3, 2, 2);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbUserStatus = new QLabel(JagunUserItem);
        lbUserStatus->setObjectName(QString::fromUtf8("lbUserStatus"));
        lbUserStatus->setMinimumSize(QSize(12, 12));
        lbUserStatus->setMaximumSize(QSize(12, 12));
        lbUserStatus->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbUserStatus);

        lbUserName = new QLabel(JagunUserItem);
        lbUserName->setObjectName(QString::fromUtf8("lbUserName"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lbUserName->setFont(font);

        horizontalLayout->addWidget(lbUserName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(31, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        lbUserMessage = new QLabel(JagunUserItem);
        lbUserMessage->setObjectName(QString::fromUtf8("lbUserMessage"));
        QFont font1;
        font1.setPointSize(8);
        lbUserMessage->setFont(font1);
        lbUserMessage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(lbUserMessage);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout);

        lbUserImage = new QLabel(JagunUserItem);
        lbUserImage->setObjectName(QString::fromUtf8("lbUserImage"));
        lbUserImage->setMinimumSize(QSize(50, 50));
        lbUserImage->setMaximumSize(QSize(50, 50));
        lbUserImage->setLayoutDirection(Qt::LeftToRight);
        lbUserImage->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbUserImage);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line = new QFrame(JagunUserItem);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        retranslateUi(JagunUserItem);

        QMetaObject::connectSlotsByName(JagunUserItem);
    } // setupUi

    void retranslateUi(QWidget *JagunUserItem)
    {
        JagunUserItem->setWindowTitle(QApplication::translate("JagunUserItem", "Form", 0, QApplication::UnicodeUTF8));
        JagunUserItem->setStyleSheet(QApplication::translate("JagunUserItem", "QWidget#JagunUserItem\n"
"{\n"
"	background-color: white;\n"
"}", 0, QApplication::UnicodeUTF8));
        lbUserStatus->setText(QApplication::translate("JagunUserItem", "S", 0, QApplication::UnicodeUTF8));
        lbUserName->setText(QApplication::translate("JagunUserItem", "name", 0, QApplication::UnicodeUTF8));
        lbUserMessage->setText(QApplication::translate("JagunUserItem", "msg", 0, QApplication::UnicodeUTF8));
        lbUserImage->setText(QApplication::translate("JagunUserItem", "I", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(JagunUserItem);
    } // retranslateUi

};

namespace Ui {
    class JagunUserItem: public Ui_JagunUserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAGUNUSERITEM_H
