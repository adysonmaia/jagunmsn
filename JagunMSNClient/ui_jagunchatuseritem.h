/********************************************************************************
** Form generated from reading ui file 'jagunchatuseritem.ui'
**
** Created: Sat May 2 21:17:55 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JAGUNCHATUSERITEM_H
#define UI_JAGUNCHATUSERITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JagunChatUserItem
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbUserImage;
    QLabel *lbUserName;

    void setupUi(QWidget *JagunChatUserItem)
    {
        if (JagunChatUserItem->objectName().isEmpty())
            JagunChatUserItem->setObjectName(QString::fromUtf8("JagunChatUserItem"));
        JagunChatUserItem->setEnabled(false);
        JagunChatUserItem->resize(81, 102);
        JagunChatUserItem->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(JagunChatUserItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 3, 0, 3);
        lbUserImage = new QLabel(JagunChatUserItem);
        lbUserImage->setObjectName(QString::fromUtf8("lbUserImage"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbUserImage->sizePolicy().hasHeightForWidth());
        lbUserImage->setSizePolicy(sizePolicy);
        lbUserImage->setMinimumSize(QSize(80, 80));
        lbUserImage->setMaximumSize(QSize(80, 80));
        lbUserImage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lbUserImage);

        lbUserName = new QLabel(JagunChatUserItem);
        lbUserName->setObjectName(QString::fromUtf8("lbUserName"));
        sizePolicy.setHeightForWidth(lbUserName->sizePolicy().hasHeightForWidth());
        lbUserName->setSizePolicy(sizePolicy);
        lbUserName->setMinimumSize(QSize(80, 16));
        lbUserName->setMaximumSize(QSize(80, 16));
        QFont font;
        font.setPointSize(7);
        font.setBold(true);
        font.setWeight(75);
        lbUserName->setFont(font);
        lbUserName->setLayoutDirection(Qt::LeftToRight);
        lbUserName->setAlignment(Qt::AlignCenter);
        lbUserName->setWordWrap(false);
        lbUserName->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(lbUserName);


        retranslateUi(JagunChatUserItem);

        QMetaObject::connectSlotsByName(JagunChatUserItem);
    } // setupUi

    void retranslateUi(QWidget *JagunChatUserItem)
    {
        JagunChatUserItem->setWindowTitle(QApplication::translate("JagunChatUserItem", "Form", 0, QApplication::UnicodeUTF8));
        JagunChatUserItem->setStyleSheet(QApplication::translate("JagunChatUserItem", "QWidget#JagunChatUserItem\n"
"{\n"
"	background-color: white;\n"
"}", 0, QApplication::UnicodeUTF8));
        lbUserImage->setText(QApplication::translate("JagunChatUserItem", "User Image", 0, QApplication::UnicodeUTF8));
        lbUserName->setText(QApplication::translate("JagunChatUserItem", "User Name", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(JagunChatUserItem);
    } // retranslateUi

};

namespace Ui {
    class JagunChatUserItem: public Ui_JagunChatUserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAGUNCHATUSERITEM_H
