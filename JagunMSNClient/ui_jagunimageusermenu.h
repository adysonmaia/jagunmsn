/********************************************************************************
** Form generated from reading ui file 'jagunimageusermenu.ui'
**
** Created: Sat May 2 21:17:55 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JAGUNIMAGEUSERMENU_H
#define UI_JAGUNIMAGEUSERMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JagunImageUserMenu
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *JagunImageUserMenu)
    {
        if (JagunImageUserMenu->objectName().isEmpty())
            JagunImageUserMenu->setObjectName(QString::fromUtf8("JagunImageUserMenu"));
        JagunImageUserMenu->resize(254, 193);
        verticalLayout = new QVBoxLayout(JagunImageUserMenu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(JagunImageUserMenu);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setIconSize(QSize(76, 76));
        listWidget->setTextElideMode(Qt::ElideNone);
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setProperty("isWrapping", QVariant(true));
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setSpacing(3);
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setSelectionRectVisible(false);

        verticalLayout->addWidget(listWidget);


        retranslateUi(JagunImageUserMenu);

        QMetaObject::connectSlotsByName(JagunImageUserMenu);
    } // setupUi

    void retranslateUi(QWidget *JagunImageUserMenu)
    {
        JagunImageUserMenu->setWindowTitle(QApplication::translate("JagunImageUserMenu", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(JagunImageUserMenu);
    } // retranslateUi

};

namespace Ui {
    class JagunImageUserMenu: public Ui_JagunImageUserMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAGUNIMAGEUSERMENU_H
