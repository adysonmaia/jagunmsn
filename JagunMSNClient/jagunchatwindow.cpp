#include "jagunchatwindow.h"


JagunChatWindow::JagunChatWindow(QWidget *parent) :
    QMainWindow(parent){
    setupUi(this);

    //lbUser->setPixmap(QPixmap(":/user/resource/user/mario.png"));

   table.setBorder(0);
   teMessageUser->setFocusPolicy(Qt::StrongFocus);


   connect(this , SIGNAL(pressEnter()), this, SLOT(sendMsg()));
   connect(btnSendMessage,SIGNAL(clicked()), this, SIGNAL(pressEnter()));

}

void JagunChatWindow::setMainUserImagem(QString imageName)
{
    lbUser->setPixmap(QPixmap(QString(":/user/resource/user/%1.png").arg(imageName)));
}

void JagunChatWindow::addGuest(QString login, QString name,QString imageName, QString message, JagunMSNContact::ECStatus status)
{
    if ( ! loginGuest.contains(login) )
    {
        lwUsers->addGuest(login,name,imageName,message,status);
        loginGuest << login;
    } else {
        lwUsers->setStateGuest(login,name,imageName,message,status);
    }
}

void JagunChatWindow::setStateGuest(QString login, QString name,QString imageName, QString message, JagunMSNContact::ECStatus status)
{
    lwUsers->setStateGuest(login,name,imageName,message,status);
}

bool JagunChatWindow::containsGuest(QStringList guests)
{
    QString login;
    if ( loginGuest.size() != guests.size()  )
    {
        return false;
    }

    foreach( login, guests )
    {
        if ( ! loginGuest.contains(login) )
        {
            return false;
        }
    }
    return true;
}

void JagunChatWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void JagunChatWindow::keyPressEvent(QKeyEvent *e)
{
    if(teMessageUser->hasFocus())
    {
        switch (e->key()) {
            case Qt::Key_Enter:
                emit pressEnter();
            case Qt::Key_Return:
                emit pressEnter();
            default:
                QWidget::keyPressEvent(e);
        }

        /*if((e->key() == Qt::Key_Enter) || (e->key() == Qt::Key_Return))
        {
            e->ignore();
            emit pressEnter();
        }*/
    }

}


void JagunChatWindow::sendMsg()
{
    showMsg(trUtf8("Voce"), teMessageUser->toPlainText());
    emit sendMessage(loginGuest,teMessageUser->toPlainText());
    teMessageUser->clear();
}

void JagunChatWindow::showMsg(QString usu, QString msg )
{
     if (usu.isEmpty() || msg.isEmpty())
     {
         return;
     }

     QTextCursor cursor(tbChat->textCursor());
     cursor.movePosition(QTextCursor::End);
     QTextTable *tablechat = cursor.insertTable(1, 2, table);
     tablechat->cellAt(0, 0).firstCursorPosition().insertText(" " + usu + " : ");
     tablechat->cellAt(0, 1).firstCursorPosition().insertText(msg);
     QScrollBar *bar = tbChat->verticalScrollBar();
     bar->setValue(bar->maximum());
     teMessageUser->setFocus();
}

void JagunChatWindow::receiveMessage(QString loginFrom, QString message)
{

    JagunChatUserItem *user = lwUsers->getItem(loginFrom);
    if ( user )
    {
        showMsg(user->getNameUser() + ": ",message);
    } else {
        showMsg("Contato",message);
    }


}

