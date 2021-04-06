#ifndef JAGUNWINDOW_H
#define JAGUNWINDOW_H

#include <QtGui/QMainWindow>
#include <QThread>
#include <QTimer>

#include "ui_jagunwindow.h"

#include "jagunclientcontroller.h"
#include "jagunadduserdialog.h"
#include "jagunmsncontact.h"


/**
 * Interface principal do jagun, todas as outras janelas sao controladas por esta classe
 */
class JagunWindow : public QMainWindow, private Ui::JagunWindow
{
    Q_OBJECT
    Q_DISABLE_COPY(JagunWindow)
public:
    /**
     * Construtor
     */
    explicit JagunWindow(QWidget *parent = 0);
    /**
     * Destrutor
     */
    ~JagunWindow();
private slots:
    /**
     * muda para a tela de novo usuario
     */
    void changeToNewUserState();
    /**
     * muda para a tela de login
     */
    void changeToLoginState();
    /**
     * valida novo usuario
     */
    void validateNewUser();
    /**
     * valida login usuario
     */
    void validateLoginUser();
    /**
     * muda o status do usuario
     */
    void changeStatusUser(QAction *action);
    /**
     * altera os status do contato nas janelas do chat que ele esta
     */
    void changeStatusContact(JagunMSNContact *contact);
    /**
     * executado quando o servidor nao esta respondendo
     */
    void serverNotResponse();
    /**
     * executado quando o servidor responde que o novo cadastro de usuario foi aceito
     */
    void successNewUser();
    /**
     * executado quando o servidor responde que o novo cadastro de usuario nao foi aceito
     */
    void failureNewUser(QString errorStr);
    /**
     * executado quando o usuario escolhe uma nova imagem
     */
    void newImage(QIcon icon,QString imageName);
    /**
     * executa quando o usuario foi logado no servidor
     */
    void successloginUser(QString nickname, QString message, QString image, int status);
    /**
     * executa quando nao foi possivel logar o usuario
     */
    void failureLoginUser(QString errorStr);
    /**
     * filtra os usuarios da lista por um determinado texto
     */
    void filterUser(const QString & text);
    /**
     * requisita para adicionar um novo usuario como amigo
     */
    void addUserRequest();
    /**
     * executa quando o usuario escolher um outro usuario para conversar
     */
    void openChatWindow(QListWidgetItem *item);
    /**
     * atualiza o nome de exibicao do usuario
     */
    void updateExibitionNameUser();
    /**
     * atualiza a mensagem do usuario
     */
    void updateMessageUser();
    /**
     * executa quando usuario faz logoff
     */
    void logoff();
    /**
     * executado no timeout no controle de tempo de ausencia
     */
    void timeoutAway();
    /**
     * executado quando algum contato pede para ser adicionado
     */
    void requestAddContact(QString login, QString message);
    /**
     * recebeu uma mensagem
     */
    void receiveMessage(QString from, QStringList to, QString message);
private:
    /**
     * limpa todas as mensagens de erro da tela de cadastro de novo usuario
     */
    void clearErrorMessageNewUserState();
    /**
     * cria todos os menus do cliente
     */
    void createMenus();
    /**
     * executado quando ocorre um evento
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     * executado quando ocorre um evento de movimento de mouse
     */
    void mouseMoveEvent(QMouseEvent *event);
    /**
     * emite atualizacao de status
     */
    void emitUpdateStatus();
    /**
     * controla a logica da comunicacao
     */
    JagunClientController *controller;
    /**
     * thread onde ira executar o controller
     */
    QThread *threadController;
    /**
     * label para mensagens na barra de status
     */
    QLabel *lbStatusBar;
    /**
     * status atual do usuario
     */
    JagunMSNContact::ECStatus currentStatus;
    /**
     * nome da imagem atual do usuario
     */
    QString currentImageName;
    /**
     * mensagem do usuario atual
     */
    QString currentMessageUser;
    /**
     * nome de exibicao do usuario atual
     */
    QString currentExibitionName;
    /**
     * janela para adicionar novo usuario
     */
    JagunAddUserDialog *addUserDialog;
    /**
     * timer de controle de tempo de ausencia
     */
    QTimer *timerAway;
signals:
    /**
     * mensagem com as informacoes de novo usuario
     */
    void newUser(QString user,QString password,QString email);
    /**
     * requsitar logar usuario no servidor
     */
    void loginUser(QString login, QString password);
    /**
     * emitido quando o usuario mudou alguma informacao
     */
    void changeStatus(QString nickname, QString message, QString image, int status, QStringList sendToo);
    /**
     * requisicao para adiconar contato a sua lista de contatos
     */
    void addContactRequest(QString login, QString message);
    /**
     * emitido em um pedido de adicionamento de contato
     */
    void addContactConfirmation(QString login, bool confirmation);
    /**
     * envia uma mensagem para uma lista de contatos
     */
    void sendMessage(QStringList to, QString message);
};

#endif // JAGUNWINDOW_H
