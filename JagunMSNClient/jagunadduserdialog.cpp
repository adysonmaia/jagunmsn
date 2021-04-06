#include "jagunadduserdialog.h"
#include <QMessageBox>

JagunAddUserDialog::JagunAddUserDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);

    QValidator *valUser  = new QRegExpValidator(QRegExp("[A-Za-z]{1}[A-Za-z0-9]{3,}"),this);
    leLoginUser->setValidator(valUser);

    connect(btnCancel,SIGNAL(clicked()),this,SLOT(cancelUser()));
    connect(btnAddUser,SIGNAL(clicked()),this,SLOT(addUser()));
}

void JagunAddUserDialog::cancelUser()
{
    close();
}

void JagunAddUserDialog::addUser()
{
    if(leLoginUser->hasAcceptableInput())
    {
        user = leLoginUser->text();
        userMessage = teMessageUser->toPlainText();
        close();
    }
    else
    {
        QMessageBox::warning(this,tr("Aviso"),trUtf8("Usuário inválido"));
    }
}

QString JagunAddUserDialog::getUser()
{
    return user;
}

QString JagunAddUserDialog::getUserMessage()
{
    return userMessage;
}
