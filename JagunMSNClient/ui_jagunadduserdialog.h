/********************************************************************************
** Form generated from reading ui file 'jagunadduserdialog.ui'
**
** Created: Sat May 2 21:17:55 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JAGUNADDUSERDIALOG_H
#define UI_JAGUNADDUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_JagunAddUserDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leLoginUser;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *teMessageUser;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAddUser;
    QPushButton *btnCancel;

    void setupUi(QDialog *JagunAddUserDialog)
    {
        if (JagunAddUserDialog->objectName().isEmpty())
            JagunAddUserDialog->setObjectName(QString::fromUtf8("JagunAddUserDialog"));
        JagunAddUserDialog->setWindowModality(Qt::NonModal);
        JagunAddUserDialog->resize(308, 172);
        JagunAddUserDialog->setMinimumSize(QSize(308, 172));
        JagunAddUserDialog->setMaximumSize(QSize(308, 172));
        verticalLayout_2 = new QVBoxLayout(JagunAddUserDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(JagunAddUserDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leLoginUser = new QLineEdit(JagunAddUserDialog);
        leLoginUser->setObjectName(QString::fromUtf8("leLoginUser"));

        horizontalLayout->addWidget(leLoginUser);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(JagunAddUserDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        teMessageUser = new QTextEdit(JagunAddUserDialog);
        teMessageUser->setObjectName(QString::fromUtf8("teMessageUser"));
        teMessageUser->setAcceptRichText(false);

        verticalLayout->addWidget(teMessageUser);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnAddUser = new QPushButton(JagunAddUserDialog);
        btnAddUser->setObjectName(QString::fromUtf8("btnAddUser"));

        horizontalLayout_2->addWidget(btnAddUser);

        btnCancel = new QPushButton(JagunAddUserDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(JagunAddUserDialog);

        QMetaObject::connectSlotsByName(JagunAddUserDialog);
    } // setupUi

    void retranslateUi(QDialog *JagunAddUserDialog)
    {
        JagunAddUserDialog->setWindowTitle(QApplication::translate("JagunAddUserDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        JagunAddUserDialog->setStyleSheet(QApplication::translate("JagunAddUserDialog", "QDialog\n"
"{\n"
"	background-color: white;\n"
"}", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JagunAddUserDialog", "Login do Usu\303\241rio::", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JagunAddUserDialog", "Mensagem de convite:", 0, QApplication::UnicodeUTF8));
        btnAddUser->setText(QApplication::translate("JagunAddUserDialog", "Adicionar", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("JagunAddUserDialog", "Cancelar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(JagunAddUserDialog);
    } // retranslateUi

};

namespace Ui {
    class JagunAddUserDialog: public Ui_JagunAddUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAGUNADDUSERDIALOG_H
