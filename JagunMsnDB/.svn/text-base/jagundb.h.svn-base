#ifndef JAGUNDB_H
#define JAGUNDB_H

#include <QObject>
#include <QString>
#include <QList>
#include <QtSql>
#include <QDir>
#include "jagunmsncontact.h"


class JagunDb : public QObject
{
  Q_OBJECT

public:

    /**
    * Construtor
    */
    JagunDb(QObject *parent = 0);
    /**
    * Destrutor
    */
    ~JagunDb();
    /**
    * Construtor
    */
    bool constatus; // Variavel que indica o Status da Cone

    enum QueryError
    {
         Qealdexist = 0, //Usuário  existe
         Qeqryfail = 1, // Consulta falhou
         Qeinsertfail  = 2, //Insers falhou
         Qeloginfail = 3,  //Login falhou
         Qeadduserfail = 4, //Adicionar usuario falhou
         Qecheckfail = 5, //Checagem de usuarios falhou
         Qegetlistfail = 6, // Pegar a lista de contatos falhou
         Qegetdatafail = 7,  //Pegar os dados do usuario falhou
         Qesetidfail = 8, //Setar o id falhou
         Qesetnickfail = 9, //Setar o nick falhou
         Qegetnickfail = 10, // Pegar o nick falhou
         Qesetstatusfail = 11, // Setar Status falhou
         Qegetstatusfail = 12,  // Pegar o Status falhou
         Qesetimagefail = 13, // Setar imagem falhou
         Qegetimagefail = 14, //Pegar imagem falhou
         Qesetusumsgfail = 15, //Setar mensagem pessoal falhou
         Qegetusumsgfail = 16, //Pegar mensagem pessoal falhou
         Qegetaddmsgfail = 17 //Pegar mensagem de adicionar contato falhou
    };

    enum LSCStatus
    {
         LSCSpendente = 0, // Relacao esta pendente
         LSCSaceito = 1
    };
    /**
    * Cria a conexao com o banco
    */
    void createNewConnection();

    /**
    * Procura no Banco por um usuario especifico
    */
    bool searchUser(QString user_login);

    /**
    * Inseri um usuario no banco
    */
    bool insertNewUser(QString login,QString mail,QString pass);

    /**
    * Loga um usuario no banco
    */
    bool loginUser(QString login,QString pass);

    /**
    * Adiciona contatos a lista, primeiro parametro eh o usuario que gerou a requisicao
    */
    bool addContact(QString login1,QString login2, QString mensagem);

    /**
    * Checa se os 2 usuarios ja sao amigos
    */
    bool checkContacts(QString login1,QString login2);

    /**
    * Fecha a conexao com o banco
    */
    void closeConnection();

    /**
    * Pega a lista de contatos do usuario
    */
    QList<JagunMSNContact *> getList(QString login);

    /**
    * Pega os dados do usuario
    */
    JagunMSNContact * getData(QString login);

    /**
    * Seta nick do usuario
    */
    bool setUsuNick(QString login, QString nick);

    /**
    * Pega o nick do usuario
    */
    QString getUsuNick(QString login);

    /**
    * Seta o Id de conexao dele
    */
    bool setIdConnection(QString login, int idcon);

    /**
    * Pega o id de conexao do usuario
    */
    int getIdConnection (QString login);

    /**
    * Seta o status do usuario
    */
    bool setUsuStatus(QString login, int status);

    /**
    * Pega status do usuario
    */
    int getUsuStatus(QString login);

    /**
    * Seta a imagem do usuario
    */
    bool setUsuImage(QString login, QString imagem);

    /**
    * Pega imagem do usuario
    */
    QString getUsuImage(QString login);

    /**
    * Seta a mensagem pessoal do usuario
    */
    bool setUsuMensagem(QString login, QString mensagem);

    /**
    * Pega mensagem pessoal do usuario
    */
    QString getUsuMensagem(QString login);

    /**
    * Pega mensagem de adicionar que o contato 1 enviou para o contato 2
    */
    QString getAddMsg(QString login, QString login2);

    /**
    * Funcao acionada quando o usuario aceita o outro, ela pega relacao do banco e coloca ambas como aceita(x,y)(y,x)
    */
    bool acceptContact(QString login,QString login2);

    /**
    * Funcao acionada quando o usuario nao aceita o outro, ela tira (x,y)(y,x) do banco
    */
    bool dontAccept(QString login,QString login2);

    /**
    * Funcao Retorna relacoes ainda nao confirmadas de um contato
    */
  QList< QPair <QString,QString > > getUnconCont(QString login);

private:

    QString serverLocation; //Local onde fica o servidor de Banco de Dados
    QString dataBaseName; //Nome do banco
    QString serverUser; //Usuario de acesso ao banco
    QString serverPass; //Senha do usuario do banco
    
    QString newUserName; //Login
    QString newUserPass; //Senha
    QString newuserMail; //Email

    QSqlDatabase dataBase;


    QueryError Qerror; //Controla os eror

    /**
    * Retonar o constatus
    */
    bool connection();
};

#endif // JAGUNDB_H
