#include "jagunwindow.h"
#include "jagunimageusermenu.h"
#include "ui_jagunwindow.h"
#include "jagunuseritem.h"
#include "jagunchatwindow.h"

#include <QValidator>
#include <QMessageBox>
#include <QMenu>
#include <QDir>
#include <QWidgetAction>
#include <QList>

JagunWindow::JagunWindow(QWidget *parent)
    : QMainWindow(parent)
{
   setupUi(this);
   //this->setAttribute(Qt::WA_DeleteOnClose);
   //QFile fileAddress("endereco.txt");
   //if (!fileAddress.open(QIODevice::ReadOnly | QIODevice::Text))
   //{
   //    QMessageBox::warning(0,"Erro","Arquivo de configuracao nao encontrado");
   //}
   //QString stringIP(fileAddress.readLine(9));
   //quint16 quiPort = fileAddress.readLine().toUInt();

   //timerAway = new QTimer(this);
   //timerAway->setInterval(5000);
   QPixmap jagunIcon(":/general/resource/general/jagunmsn.png");
   lbJagunImage->setPixmap(jagunIcon.scaled(QSize(167,80),Qt::KeepAspectRatio,Qt::SmoothTransformation));

   // escondendo widgets inuteis por enquanto
   //lbJagunImage->setVisible(false);
   toolBar->setVisible(false);
   chbRememberPassword->setVisible(false);
   btnForgotPassword->setVisible(false);
   btnFilterUser->setVisible(false);

   createMenus();

   currentImageName = "default";
   currentStatus = JagunMSNContact::ECSOffline;
   leExibitionNameUser->setText(tr("Login"));
   leMsgUser->setText(tr("Desconectado"));

   threadController = new QThread();
   QHostAddress serverHost("10.0.0.118");
   //QHostAddress serverHost = QHostAddress::LocalHost;

   controller = new JagunClientController(serverHost,9999);
   // movendo o controller para sua thread
   controller->moveToThread(threadController);
   lbStatusBar = new QLabel();

   // mensagen na status bar
   this->sbStatusBar->addWidget(lbStatusBar);

   // set validators de cada campo
   QValidator *valUser     = new QRegExpValidator(QRegExp("[A-Za-z]{1}[A-Za-z0-9]{3,}"),this);
   QValidator *valPassword = new QRegExpValidator(QRegExp("[A-Za-z0-9]{4,}"),this);
   QValidator *valEmail    = new QRegExpValidator(QRegExp("^[\\w-]+(\\.[\\w-]+)*@(([\\w-]{2,63}\\.)+[A-Za-z]{2,6}|\\[\\d{1,3}(\\.\\d{1,3}){3}\\])$"),this);

   // validators da tela de novo usuario
   leLoginNewUser->setValidator(valUser);
   leEmailNewUser->setValidator(valEmail);
   lePasswordNewUser->setValidator(valPassword);
   leConfirmPasswordNewUser->setValidator(valPassword);

   // validators da tela de login
   leLoginUser->setValidator(valUser);
   lePasswordUser->setValidator(valPassword);

   // primeira tela a ser exibida
   stackedWidgetMain->setCurrentWidget(swmLogin);
   //stackedWidgetMain->setCurrentWidget(swmConnected);

   // sinais e slots
   connect(btnNewUser,SIGNAL(clicked()),this,SLOT(changeToNewUserState()));
   connect(btnCancelNewUser,SIGNAL(clicked()),this,SLOT(changeToLoginState()));
   connect(btnRegisterNewUser,SIGNAL(clicked()),this,SLOT(validateNewUser()));
   connect(btnEnter,SIGNAL(clicked()),this,SLOT(validateLoginUser()));
   connect(this,SIGNAL(newUser(QString,QString,QString)),controller,SLOT(newUser(QString,QString,QString)));
   connect(this,SIGNAL(loginUser(QString,QString)),controller,SLOT(loginUser(QString,QString)));
   connect(controller,SIGNAL(serverNotResponse()),this,SLOT(serverNotResponse()));
   connect(controller,SIGNAL(successNewUser()),this,SLOT(successNewUser()));
   connect(controller,SIGNAL(failureNewUser(QString)),this,SLOT(failureNewUser(QString)));
   connect(controller,SIGNAL(successloginUser(QString,QString,QString,int)),this,SLOT(successloginUser(QString,QString,QString,int)));
   connect(controller,SIGNAL(failureLoginUser(QString)),this,SLOT(failureLoginUser(QString)));
   connect(leSearchUser,SIGNAL(textChanged(QString)),this,SLOT(filterUser(QString)));
   connect(btnAddUser,SIGNAL(clicked()),this,SLOT(addUserRequest()));
   connect(lwUsers,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(openChatWindow(QListWidgetItem*)));
   connect(controller,SIGNAL(contactList(QList<JagunMSNContact*>)),lwUsers,SLOT(setContactList(QList<JagunMSNContact*>)));
   connect(leExibitionNameUser,SIGNAL(returnPressed()),this,SLOT(updateExibitionNameUser()));
   connect(leMsgUser,SIGNAL(returnPressed()),this,SLOT(updateMessageUser()));
   connect(this,SIGNAL(changeStatus(QString,QString,QString,int,QStringList)),controller,SLOT(changeStatus(QString,QString,QString,int,QStringList)));
   connect(controller,SIGNAL(logoff()),this,SLOT(logoff()));
   connect(this,SIGNAL(addContactRequest(QString,QString)),controller,SLOT(addContact(QString,QString)));
   //connect(timerAway,SIGNAL(timeout()),this,SLOT(timeoutAway()));
   connect(this,SIGNAL(addContactConfirmation(QString,bool)),controller,SLOT(addContactConfirmation(QString,bool)));
   connect(controller,SIGNAL(requestAddContact(QString,QString)),this,SLOT(requestAddContact(QString,QString)));
   connect(controller,SIGNAL(newContact(JagunMSNContact*)),lwUsers,SLOT(addNewContact(JagunMSNContact*)));
   connect(controller,SIGNAL(contactChangeStatus(JagunMSNContact*)),lwUsers,SLOT(contactChangeStatus(JagunMSNContact*)));
   connect(controller,SIGNAL(contactChangeStatus(JagunMSNContact*)),this,SLOT(changeStatusContact(JagunMSNContact*)));
   connect(controller,SIGNAL(receiveMessage(QString, QStringList, QString)),this,SLOT(receiveMessage(QString, QStringList, QString) ) );
   connect(this,SIGNAL(sendMessage(QStringList, QString)),controller,SLOT(sendMessage(QStringList, QString) ) );

   // iniciando o controller
   threadController->start();
}

JagunWindow::~JagunWindow()
{
}

void JagunWindow::changeToNewUserState()
{
    // limpa mensagens de erro
    clearErrorMessageNewUserState();

    // limpando inputs
    leLoginNewUser->clear();
    leEmailNewUser->clear();
    lePasswordNewUser->clear();
    leConfirmPasswordNewUser->clear();

    stackedWidgetMain->setCurrentWidget(swmNewUser);
}

void JagunWindow::changeToLoginState()
{
    leLoginUser->clear();
    lePasswordUser->clear();
    stackedWidgetMain->setCurrentWidget(swmLogin);
}

void JagunWindow::validateNewUser()
{
    clearErrorMessageNewUserState();
    bool isError = false;

    if(!leEmailNewUser->hasAcceptableInput())
    {
        lbErrorEmailNewUser->setText(trUtf8("Email invalido"));
        lbErrorEmailNewUser->setVisible(true);
        isError = true;
    }

    if(!leLoginNewUser->hasAcceptableInput())
    {
        lbErrorLoginNewUser->setText(trUtf8("Usuário invalido"));
        lbErrorLoginNewUser->setVisible(true);
        isError = true;
    }

    if(!lePasswordNewUser->hasAcceptableInput())
    {
        lbErrorPasswordNewUser->setText(trUtf8("Senha invalida"));
        lbErrorPasswordNewUser->setVisible(true);
        isError = true;
    }

    if(leConfirmPasswordNewUser->text() != lePasswordNewUser->text())
    {
        lbErrorConfirmPasswordNewUser->setText(trUtf8("Confirmacao de senha nao confere"));
        lbErrorConfirmPasswordNewUser->setVisible(true);
        isError = true;
    }

    if(isError)
    {
        QMessageBox::warning(this,tr("Aviso"),trUtf8("Dados invalidos"));
        return;
    }

    stackedWidgetMain->setEnabled(false);
    lbStatusBar->setText("Validando Cadastro. Aguarde...");
    emit newUser(leLoginNewUser->text(),lePasswordNewUser->text(),leEmailNewUser->text());
}

void JagunWindow::clearErrorMessageNewUserState()
{
    lbErrorEmailNewUser->setVisible(false);
    lbErrorLoginNewUser->setVisible(false);
    lbErrorPasswordNewUser->setVisible(false);
    lbErrorConfirmPasswordNewUser->setVisible(false);

    //lbErrorEmailNewUser->setText("");
    //lbErrorLoginNewUser->setText("");
    //lbErrorPasswordNewUser->setText("");
    //lbErrorConfirmPasswordNewUser->setText("");
}

void JagunWindow::createMenus()
{
    // menu de status
    QMenu *statusMenu = new QMenu(btnStatusUser);
    statusMenu->addAction(actStatusAvailable);
    statusMenu->addAction(actStatusBusy);
    statusMenu->addAction(actStatusAway);
    statusMenu->addAction(actStatusInvisible);

    btnStatusUser->setMenu(statusMenu);

    // menu da imagem de usuarios
    QMenu *imageUserMenu = new QMenu(btnImageUser);
    QWidgetAction *actImageUser = new QWidgetAction(imageUserMenu);
    JagunImageUserMenu *jium = new JagunImageUserMenu(imageUserMenu);

    jium->loadUserImages(QDir(":/user/resource/user"));
    imageUserMenu->resize(10,10);
    btnImageUser->setIcon(*jium->defaultImage());

    actImageUser->setDefaultWidget(jium);

    imageUserMenu->addAction(actImageUser);

    btnImageUser->setMenu(imageUserMenu);


    connect(statusMenu,SIGNAL(triggered(QAction*)),this,SLOT(changeStatusUser(QAction*)));
    connect(jium,SIGNAL(newImage(QIcon,QString)),this,SLOT(newImage(QIcon,QString)));
}

void JagunWindow::changeStatusUser(QAction *action)
{
    btnStatusUser->setIcon(action->icon());
    currentStatus = JagunMSNContact::ECStatus(action->property("statusType").toUInt());
    qDebug() << "JagunWindow:: Mudou o status:" << currentStatus;
    emitUpdateStatus();

}

void JagunWindow::serverNotResponse()
{
    lbStatusBar->clear();
    // remover todas as janelas de chat
    QList<JagunChatWindow*> listChats = this->findChildren<JagunChatWindow*>();
    JagunChatWindow *chat;
    foreach (chat, listChats)
    {
        chat->close();
        delete chat;
    }
    if(stackedWidgetMain->currentWidget() == swmConnected)
    {

        //timerAway->stop();
       qDebug() << "JagunWindow:: Servidor nao responde";
       currentImageName = "default";
       currentMessageUser.clear();
       currentExibitionName.clear();
       currentStatus = JagunMSNContact::ECSOffline;
       btnImageUser->setIcon(QIcon(":/user/resource/user/default.png"));
       btnImageUser->setEnabled(false);
       btnStatusUser->setIcon(QIcon(":icons/3"));
       btnStatusUser->setEnabled(false);
       leExibitionNameUser->setText(tr("Login"));
       leExibitionNameUser->setEnabled(false);
       leMsgUser->setText(tr("Desconectado"));
       leMsgUser->setEnabled(false);
       lbStatusBar->clear();
       stackedWidgetMain->setCurrentWidget(swmLogin);
    }

    QMessageBox::warning(this,tr("Aviso"),trUtf8("Servidor nao responde"));
    stackedWidgetMain->setEnabled(true);
}

void JagunWindow::successNewUser()
{
    stackedWidgetMain->setCurrentWidget(swmLogin);
    stackedWidgetMain->setEnabled(true);
    lbStatusBar->clear();
    QMessageBox::warning(this,tr("Aviso"),trUtf8("Usuario cadastrado. Voce agora pode conversar"));
}

void JagunWindow::failureNewUser(QString errorStr)
{
    stackedWidgetMain->setEnabled(true);
    lbStatusBar->clear();
    QMessageBox::warning(this,tr("Aviso"),errorStr);
    lbErrorLoginNewUser->setText(trUtf8("Usuario existente. Escolha outro..."));
    lbErrorLoginNewUser->setVisible(true);
}

void JagunWindow::newImage(QIcon icon,QString imageName)
{
    btnImageUser->menu()->close();
    if(imageName == currentImageName)
        return;

    currentImageName = imageName;
    btnImageUser->setIcon(icon);
    qDebug() << "Mudou a imagem";
    emitUpdateStatus();
}

void JagunWindow::validateLoginUser()
{
    QString errorMsg;

    if(!leLoginUser->hasAcceptableInput())
    {
        errorMsg.append(trUtf8("Login invalido.\n"));
    }

    if(!lePasswordUser->hasAcceptableInput())
    {
        errorMsg.append(trUtf8("Senha invalida.\n"));
    }

    if(errorMsg.length() > 0)
    {
        QMessageBox::warning(this,tr("Aviso"),errorMsg);
        return;
    }

    stackedWidgetMain->setEnabled(false);
    lbStatusBar->setText("Aguarde...");
    emit loginUser(leLoginUser->text(),lePasswordUser->text());
}

void JagunWindow::successloginUser(QString nickname, QString message, QString image, int status)
{
    stackedWidgetMain->setEnabled(true);
    lbStatusBar->clear();
    btnStatusUser->setEnabled(true);
    btnImageUser->setEnabled(true);
    leExibitionNameUser->setEnabled(true);
    leMsgUser->setEnabled(true);

    stackedWidgetMain->setCurrentWidget(swmConnected);
    //timerAway->stop();
    //timerAway->start();

    // status do usuario
    QString iconStatusName = QString(":/icons/%1").arg(status);
    currentStatus = JagunMSNContact::ECStatus(status);
    btnStatusUser->setIcon(QIcon(iconStatusName));

    // imagem de exibicao
    QString iconImageName = QString(":/user/resource/user/%1").arg(image) + QString(".png");
    currentExibitionName = image;
    btnImageUser->setIcon(QIcon(iconImageName));

    // ultimo nickname
    leExibitionNameUser->setText(nickname);
    currentExibitionName = nickname;

    // ultima mensagem do usuario
    leMsgUser->setText(message);
    currentMessageUser = message;
}

void JagunWindow::failureLoginUser(QString errorStr)
{
    stackedWidgetMain->setEnabled(true);
    lbStatusBar->clear();
    QMessageBox::warning(this,tr("Aviso"),errorStr);
}

void JagunWindow::filterUser(const QString & text)
{
    QListWidgetItem *item = 0;
    JagunUserItem *userItem = 0;
    for(int i = 0; i < lwUsers->count(); i++)
    {
        item = lwUsers->item(i);
        userItem = qobject_cast<JagunUserItem*>(lwUsers->itemWidget(item));
        if(userItem->getNameUser().contains(text,Qt::CaseInsensitive))
        {
            item->setHidden(false);
        }
        else
        {
            item->setHidden(true);
        }
    }
}

void JagunWindow::addUserRequest()
{
    addUserDialog = new JagunAddUserDialog(this);

    // posicao do dialogo fica em cima do botao
    QPoint globalBtnPosition = this->mapToGlobal(btnAddUser->pos());
    // nao me pergunte por que :p
    //addUserDialog->move(globalBtnPosition.x(),globalBtnPosition.y() - ((int) addUserDialog->height()/2) - 3);
    addUserDialog->exec();

    emit addContactRequest(addUserDialog->getUser(),addUserDialog->getUserMessage());
    delete addUserDialog;
    addUserDialog = 0;

}

void JagunWindow::openChatWindow(QListWidgetItem* item)
{
    // tenta encontrar um chat ja criado
    JagunUserItem *user = qobject_cast<JagunUserItem*>(lwUsers->itemWidget(item));
    if(user->getStatusUser() == JagunMSNContact::ECSOffline)
    {
        QMessageBox::warning(this,"Aviso",trUtf8("Impossivel iniciar uma conversa pois o usuario esta desconectado"));
        return;
    }

    QList<JagunChatWindow*> listChats = this->findChildren<JagunChatWindow*>();
    JagunChatWindow *chat;
    bool find;

    QStringList listGuest;
    listGuest << user->getLoginUser();

    find = false;
    foreach (chat, listChats )
    {
        if (  chat->containsGuest(listGuest)  )
        {
            find = true;
            chat->setStateGuest(user->getLoginUser(), user->getNameUser(), user->getImageUser(), user->getMessageUser(),user->getStatusUser() );
            chat->show();
            chat->setFocus();
        }
    }

    if (!find )
    {
        chat = new JagunChatWindow(this);
        //this->setAttribute(Qt::WA_DeleteOnClose);
        connect(chat, SIGNAL(sendMessage(QStringList, QString)), this, SIGNAL(sendMessage(QStringList, QString)) );
        chat->setMainUserImagem(currentImageName);
        chat->addGuest(user->getLoginUser(), user->getNameUser(), user->getImageUser(), user->getMessageUser(),user->getStatusUser() );
        chat->show();
        chat->setFocus();
    }

}

void JagunWindow::updateExibitionNameUser()
{
    if(leExibitionNameUser->text().length() == 0)
    {
        QMessageBox::warning(this,tr("Aviso"),"Esse campo nao pode ser vazio");
        leExibitionNameUser->setText(currentExibitionName);
        return;
    }
    qDebug() << "Mudou o nick";
    currentExibitionName = leExibitionNameUser->text();
    emitUpdateStatus();

}

void JagunWindow::updateMessageUser()
{
    if(leMsgUser->text().length() == 0)
    {
        QMessageBox::warning(this,tr("Aviso"),"Esse campo nao pode ser vazio");
        leMsgUser->setText(currentMessageUser);
        return;
    }
    qDebug() << "Mudou a mensagem";
    currentMessageUser = leMsgUser->text();
    emitUpdateStatus();
}

void JagunWindow::logoff()
{
    QList<JagunChatWindow*> listChats = this->findChildren<JagunChatWindow*>();
    JagunChatWindow *chat;
    foreach (chat, listChats)
    {
        chat->close();
        delete chat;
    }
   qDebug() << "JagunWindow:: Fez logoff";
   currentImageName = "default";
   currentMessageUser.clear();
   currentExibitionName.clear();
   currentStatus = JagunMSNContact::ECSOffline;
   btnImageUser->setIcon(QIcon(":/user/resource/user/default.png"));
   btnImageUser->setEnabled(false);
   btnStatusUser->setIcon(QIcon(":icons/3"));
   btnStatusUser->setEnabled(false);
   leExibitionNameUser->setText(tr("Login"));
   leExibitionNameUser->setEnabled(false);
   leMsgUser->setText(tr("Desconectado"));
   leMsgUser->setEnabled(false);
   lbStatusBar->clear();
   stackedWidgetMain->setEnabled(true);
   stackedWidgetMain->setCurrentWidget(swmLogin);
   QMessageBox::warning(this,tr("Aviso"),"Voce foi desconectado");
}

void JagunWindow::keyPressEvent(QKeyEvent *event)
{
    /*qDebug() << "JagunWindow::keyPressEvent";
    if(stackedWidgetMain->currentWidget() == swmConnected)
    {
        timerAway->stop();
        timerAway->start();
    }*/
    QWidget::keyPressEvent(event);
}

void JagunWindow::mouseMoveEvent(QMouseEvent *event)
{
    // a propriedade mousetracking = true foi setado no arquivo ui
    /*qDebug() << "JagunWindow::mouseMoveEvent";
    if(stackedWidgetMain->currentWidget() == swmConnected)
    {
        timerAway->stop();
        if(currentStatus != JagunMSNContact::ECSAway)
        {
            timerAway->start();
        }
    }*/
    QWidget::mouseMoveEvent(event);
}

void JagunWindow::timeoutAway()
{
    qDebug() << "JagunWindow:: usuario muito tempo inativo";
    currentStatus = JagunMSNContact::ECSAway;
    btnStatusUser->setIcon(QIcon(":icons/3"));
    emitUpdateStatus();
}

void JagunWindow::emitUpdateStatus()
{
    //timerAway->stop();
    //TODO - recuperar os convidados se existir
    QStringList sendTooList;
    emit changeStatus(currentExibitionName, currentMessageUser, currentImageName, (int) currentStatus, sendTooList);

    QList<JagunChatWindow*> listChats= this->findChildren<JagunChatWindow*>();
    JagunChatWindow *chat;
    foreach (chat, listChats )
    {
        chat->setMainUserImagem(currentImageName);
    }
}

void JagunWindow::requestAddContact(QString login, QString message)
{
    QString solicitation = login + " : \n\t" + message;
    QMessageBox::StandardButton button = QMessageBox::question(this,"Convite de novo usuario",solicitation,QMessageBox::Ok | QMessageBox::No);
    bool result = (button == QMessageBox::Ok)? true : false ;
    emit addContactConfirmation(login,result);

}

void JagunWindow::changeStatusContact(JagunMSNContact *contact)
{
    QList<JagunChatWindow*> listChats= this->findChildren<JagunChatWindow*>();
    JagunChatWindow *chat;
    foreach (chat, listChats )
    {
        chat->setStateGuest(contact->getLogin(), contact->getNickname(), contact->getImage(),
                            contact->getMessage(),contact->getStatus() );
    }
}

void JagunWindow::receiveMessage(QString from, QStringList to, QString message)
{
    QList<JagunChatWindow*> listChats= this->findChildren<JagunChatWindow*>();
    QStringList listContacts = to;
    listContacts.append(from);


    JagunChatWindow *chat = 0;
    bool find = false;
    foreach (chat, listChats )
    {
        if ( chat->containsGuest(listContacts) )
        {
            find = true;
            chat->show();
            chat->setFocus();
            chat->receiveMessage(from,message);
            break;
        }
    }

    if( ! find)
    {
        chat = new JagunChatWindow(this);
        connect(chat, SIGNAL(sendMessage(QStringList, QString)), this, SIGNAL(sendMessage(QStringList, QString)) );
        chat->setMainUserImagem(currentImageName);

        QString loginContact;

        foreach (loginContact, listContacts)
        {
            JagunUserItem *user;
            user = lwUsers->getItem(loginContact);
            if ( user ) {
                chat->addGuest(user->getLoginUser(), user->getNameUser(), user->getImageUser(),
                               user->getMessageUser(),user->getStatusUser() );
            }
        }

        chat->show();
        chat->setFocus();
        chat->receiveMessage(from,message);
    }

    //TODO - enviar mensagem para a janela
}
