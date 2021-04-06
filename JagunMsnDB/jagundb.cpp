#include "jagundb.h"

//Construtor da Classe
JagunDb::JagunDb(QObject *parent)
   : QObject(parent)
{
    serverLocation = "";
    serverUser = "";
    serverPass = "" ;
    dataBaseName = "JagunDB.sqlite";
    //dataBaseName = "/home/adyson/Desktop/JagunDB.sqlite";
    //dataBaseName = "C:\\Users\\Schwarzenegger\\Documents\\QtProjects\\Jagumsn\\JagunMsnDB\\JagunDB.sqlite";
    constatus = false;
}

//Destrutor da Classe
JagunDb::~JagunDb()
{
}


void JagunDb::createNewConnection()
{

     dataBase = QSqlDatabase::addDatabase("QSQLITE");  // Escolha do driver
//     db.setHostName("serverLocation"); //Escolha do Host
     dataBase.setDatabaseName(dataBaseName); //Escolha do nome do Banco
//     db.setUserName("serverUser"); //Usuario do Banco
//     db.setPassword("serverUser"); //Senha do Usuario do banco

     if (!dataBase.open()) //Verifica se foi  possivel se conectar ao banco
     {
      qDebug() << "Falha ao se Conectar ao banco"  << dataBaseName;
      constatus = true;
      connection();
     }
     else
     {
      qDebug() << "Voce se Conectou em " << dataBaseName;
      constatus = false;
      connection();
     }
}

//Retorna constatus
bool JagunDb::connection()
{
  return constatus;
}


//Funçao para procurar um usuario no Banco
bool JagunDb::searchUser(QString user_login)
{
    QString name;
    QString login;
    QSqlQuery query;

    query.exec("SELECT * FROM usu_usuario"); //seleciona todos os usuario

    if (!query.isActive()){    // Verifica se a consulta deu certo
    qDebug() << "Error"  << query.lastError().text();
    Qerror = Qeqryfail;
    return false;
    }

    while( query.next() ) //procura pelos usuarios
    {
     login = query.value(1).toString();
     if (login == user_login)
     {
         qDebug() << "Error usuario ja existe" ;
         Qerror = Qealdexist;
         return false;
     }
    }
    qDebug() << "pode inserir";
    return true;
}

//Funcao de insercao
bool JagunDb::insertNewUser(QString login,QString mail,QString pass)
{
   newUserName = login;
   newuserMail = mail;
   newUserPass = pass;

   if (searchUser(newUserName) == true)
   {
      QSqlQuery insertquery;
      insertquery.prepare("INSERT INTO usu_usuario (usu_login, usu_email, usu_pass , usu_nick , usu_status , usu_laststatus , usu_imagem, usu_idcon, usu_mensagem) "
                          "VALUES (:usu_login, :usu_email, :usu_pass, :usu_nick , :usu_status, :usu_laststatus, :usu_imagem, :usu_idcon, :usu_mensagem)");
      insertquery.bindValue(":usu_login", newUserName);
      insertquery.bindValue(":usu_email", newuserMail);
      insertquery.bindValue(":usu_pass", newUserPass);
      insertquery.bindValue(":usu_nick" , newUserName);
      insertquery.bindValue(":usu_status", 1);
      insertquery.bindValue(":usu_laststatus", 1);
      insertquery.bindValue(":usu_imagem", "default");
      insertquery.bindValue(":usu_idcon",-1);
      insertquery.bindValue(":usu_mensagem","Ola");

      insertquery.exec();
      if (!insertquery.isActive())
      {
        qDebug() << "A Insercao falhou" << insertquery.lastError().text() ;
        Qerror = Qeinsertfail;
        return false;
      }
      else
      {
        qDebug() << "Foi inserido uma linha na tabela";
        return true;
      }
   }
   else
   {
      return false;
   }
}
//Funcao de Login
bool JagunDb::loginUser(QString login,QString pass)
{
    newUserName = login;
    newUserPass = pass;

    QString userLogin;
    QString userPass;

    QSqlQuery loginquery;
    loginquery.prepare("SELECT usu_login , usu_pass FROM usu_usuario WHERE usu_login = ? AND usu_pass = ?");
    loginquery.addBindValue(newUserName);
    loginquery.addBindValue(newUserPass);
    loginquery.exec();

    if (!loginquery.isActive())
    {
      qDebug() << "Error"  << loginquery.lastError().text();
      Qerror = Qeloginfail;
      return false;
    }
    else
    {
      loginquery.next();
      userLogin = loginquery.value(0).toString();
      userPass =  loginquery.value(1).toString();

      if ((newUserName == userLogin) && (newUserPass == userPass))
      {
         qDebug() << "Voce esta logado";
         return true;
      }
      else
      {
        qDebug() << "Voce nao esta logado" << userPass;
        return false;
      }
    }

}


bool JagunDb::addContact(QString login1, QString login2, QString mensagem)
{
     QSqlQuery adduserquery1;
     QSqlQuery adduserquery2;

     if(checkContacts(login1,login2))
     {

       adduserquery1.prepare("INSERT INTO lsc_listcont (usu_login1, usu_login2, lsc_status, lsc_mensagem)"
                              "VALUES (:usu_login1,:usu_login2,:lsc_status, :lsc_mensagem)");
       adduserquery1.bindValue(":usu_login1", login1);
       adduserquery1.bindValue(":usu_login2", login2);
       adduserquery1.bindValue(":lsc_status", 0);
       adduserquery1.bindValue(":lsc_mensagem", mensagem);
       adduserquery1.exec();
       if (!adduserquery1.isActive())
       {
          qDebug() << "A Insercao na tabela da lista de contatos falhou falhou" << adduserquery1.lastError().text() ;
          Qerror = Qeadduserfail;
          return false;
       }
       else //relacao inversa
       {
          adduserquery2.prepare("INSERT INTO lsc_listcont (usu_login1, usu_login2, lsc_status)"
                              "VALUES (:usu_login1,:usu_login2,:lsc_status)");
          adduserquery2.bindValue(":usu_login1", login2);
          adduserquery2.bindValue(":usu_login2", login1);
          adduserquery2.bindValue(":lsc_status", 0); //Discutir sobre esse id
          adduserquery2.exec();
          if (!adduserquery2.isActive())
          {
            qDebug() << "A Segunda Insercao na tabela da lista de contatos falhou falhou" << adduserquery2.lastError().text() ;
            Qerror = Qeadduserfail;
            QSqlQuery deletequery;
            deletequery.prepare("DELETE FROM lsc_listcont WHERE usu_login1 = ? AND usu_login2 = ?");
            deletequery.addBindValue(login1);
            deletequery.addBindValue(login2);
            deletequery.exec();
            return false;
         }
         else
         {
            qDebug() <<"Contatos agoram sao amigos";
            return true;
         }
       }
   }
   else
   {
     return false;
   }
}

bool JagunDb::checkContacts(QString login1, QString login2)
{
    QSqlQuery checkquery;
    checkquery.prepare("SELECT usu_login1, usu_login2 FROM lsc_listcont WHERE usu_login1 = ? AND usu_login2 = ?");
    checkquery.addBindValue(login1);
    checkquery.addBindValue(login2);
    checkquery.exec();

    if (!checkquery.isActive())
    {
      qDebug() << "Error"  << checkquery.lastError().text();
      Qerror = Qecheckfail;
      return false;
    }
    else
    {
      checkquery.next();
      QString userL1 = checkquery.value(0).toString();
      QString userL2 = checkquery.value(1).toString();

      if ((userL1 == login1) && (userL2 == login2))
      {
         qDebug() << "Ja sao amigos";
         return false;
      }
      else
      {
        qDebug() << "nao sao amigos";
        return true;
      }
    }
}

void JagunDb::closeConnection()
{
  dataBase.close();
}


QList<JagunMSNContact *> JagunDb::getList(QString login)
{
    QSqlQuery getlistquery;
    QSqlQuery getcontactquery;
    QString contactlogin;
    QString contactloginteste;
    QList<JagunMSNContact*> list;
    QString usu_login;
    QString usu_nick;
    QString usu_mensagem;
    QString usu_imagem;
    QString usu_email;
    int usu_status;
    JagunMSNContact::ECStatus status;
    int usu_laststatus;
    JagunMSNContact::ECStatus laststatus;


    getlistquery.prepare("SELECT * FROM lsc_listcont WHERE usu_login1 = ? AND lsc_status = ?");
    getlistquery.addBindValue(login);
    getlistquery.addBindValue(1);
    getlistquery.exec();
    if (!getlistquery.isActive())
    {
      qDebug() << "Error"  << getlistquery.lastError().text();
      Qerror = Qegetlistfail;

    }
    else
    {
      while( getlistquery.next() ) //procura pelos usuarios
      {
        contactlogin = getlistquery.value(1).toString();
        getcontactquery.prepare("SELECT usu_login, usu_nick, usu_mensagem, usu_imagem, usu_email, usu_status, usu_laststatus FROM usu_usuario WHERE usu_login= ?");
        getcontactquery.addBindValue(contactlogin);
        getcontactquery.exec();
        if (!getcontactquery.isActive())
        {
            qDebug() << "Error"  << getcontactquery.lastError().text();
            Qerror = Qegetlistfail;
        }
           getcontactquery.next();
           usu_login = getcontactquery.value(0).toString();
           usu_nick = getcontactquery.value(1).toString();
           usu_mensagem = getcontactquery.value(2).toString();
           usu_imagem = getcontactquery.value(3).toString();
           usu_email = getcontactquery.value(4).toString();
           usu_status = getcontactquery.value(5).toInt();
           usu_laststatus = getcontactquery.value(6).toInt();

           status = JagunMSNContact::ECStatus(usu_status );

           laststatus =  JagunMSNContact::ECStatus(usu_laststatus);

           JagunMSNContact *contact = new  JagunMSNContact();
           contact->setLogin( usu_login );
           contact->setNickname(usu_nick );
           contact->setMessage(usu_mensagem);
           contact->setImage(usu_imagem);
           contact->setEmail(usu_email);
           contact->setStatus(status);
           contact->setLastStatus(laststatus);
           list << contact;


     }
      return list;
    }

}

JagunMSNContact * JagunDb::getData(QString login)
{
    QSqlQuery getdataquery;
    QString usu_login;
    QString usu_nick;
    QString usu_mensagem;
    QString usu_imagem;
    QString usu_email;
    int usu_status;
    JagunMSNContact::ECStatus status;
    int usu_laststatus;
    JagunMSNContact::ECStatus laststatus;
    QList<QString> usuData;
    QList<JagunMSNContact*> list;

    getdataquery.prepare("SELECT usu_login, usu_nick, usu_mensagem, usu_imagem, usu_email, usu_status, usu_laststatus FROM usu_usuario WHERE usu_login= ?");
    getdataquery.addBindValue(login);
    getdataquery.exec();
    if (!getdataquery.isActive())
    {
        qDebug() << "Error"  << getdataquery.lastError().text();
        Qerror = Qegetdatafail;

    }
    else
    {

           getdataquery.next();  //procura pelos usuarios
           usu_login = getdataquery.value(0).toString();
           usu_nick = getdataquery.value(1).toString();
           usu_mensagem = getdataquery.value(2).toString();
           usu_imagem = getdataquery.value(3).toString();
           usu_email = getdataquery.value(4).toString();
           usu_status = getdataquery.value(5).toInt();
           usu_laststatus = getdataquery.value(6).toInt();

           status = JagunMSNContact::ECStatus(usu_status );

           laststatus =  JagunMSNContact::ECStatus(usu_laststatus);

           JagunMSNContact *contact = new  JagunMSNContact();
           contact->setLogin( usu_login );
           contact->setNickname(usu_nick );
           contact->setMessage(usu_mensagem);
           contact->setImage(usu_imagem);
           contact->setEmail(usu_email);
           contact->setStatus(status);
           contact->setLastStatus(laststatus);
           list << contact;



           return (contact);
    }

}

bool JagunDb::setIdConnection(QString login, int idcon)
{
    QSqlQuery setidquery;
    setidquery.prepare("UPDATE usu_usuario SET usu_idcon = ? WHERE usu_login = ?");
    setidquery.addBindValue(idcon);
    setidquery.addBindValue(login);
    setidquery.exec();
    if (!setidquery.isActive())
    {
        qDebug() << "Error"  << setidquery.lastError().text();
        Qerror = Qesetidfail;
        return false;
    }
    else
    {
         if(setidquery.numRowsAffected() > 0)
         {
           qDebug() << "Novo id de comunicacao setado";
           return true;
         }

         else
         {
             qDebug() << "Usuario nao encontrado";
             Qerror = Qesetidfail;
             return false;
         }
     }

}

int JagunDb::getIdConnection(QString login)
{
    QSqlQuery getidquery;
    QString userLogin;
    int idcon;

    getidquery.prepare("SELECT usu_login, usu_idcon FROM usu_usuario WHERE usu_login = ?");
    getidquery.addBindValue(login);
    getidquery.exec();
    if (!getidquery.isActive())
    {
        qDebug() << "Error"  << getidquery.lastError().text();
        Qerror = Qesetidfail;
        return -1;
    }
    else
    {

        getidquery.next();
        userLogin = getidquery.value(0).toString();
        idcon = getidquery.value(1).toInt();
        if(login == userLogin)
        {
           qDebug() << "Retornando id do usuario";
           return idcon;
        }
        else
        {
           qDebug() << "Usuario non ecxiste";                  
           return -1;
        }
    }
}

bool JagunDb ::setUsuNick(QString login, QString nick)
{
    QSqlQuery setusunickquery;

    setusunickquery.prepare("UPDATE usu_usuario SET usu_nick = ? WHERE usu_login = ?");
    setusunickquery.addBindValue(nick);
    setusunickquery.addBindValue(login);
    setusunickquery.exec();
    if (!setusunickquery.isActive())
    {
        qDebug() << "Error"  << setusunickquery.lastError().text();
        Qerror = Qesetnickfail;
        return false;
    }
    else
    {
         if(setusunickquery.numRowsAffected() > 0)
         {
           qDebug() << "Novo Nick setado";
           return true;
         }

         else
         {
             qDebug() << "Usuario nao encontrado";
             Qerror = Qesetnickfail;
             return false;
         }
     }
}

QString JagunDb::getUsuNick(QString login)
{
    QSqlQuery getusunickquery;

    QString userLogin;
    QString nick;

    getusunickquery.prepare("SELECT usu_login, usu_nick FROM usu_usuario WHERE usu_login = ?");
    getusunickquery.addBindValue(login);
    getusunickquery.exec();
    if (!getusunickquery.isActive())
    {
        qDebug() << "Error"  << getusunickquery.lastError().text();
        Qerror = Qegetnickfail;
        return 0;
    }
    else
    {

        getusunickquery.next();
        userLogin = getusunickquery.value(0).toString();
        nick = getusunickquery.value(1).toString();
        if(login == userLogin)
        {
           qDebug() << "Retornando nick do usuario";
           return nick;
        }
        else
        {
           qDebug() << "Usuario non ecxiste";
           Qerror = Qegetnickfail;
           return 0;
        }
    }

}

bool JagunDb::setUsuStatus(QString login, int status)
{
    QSqlQuery setusustatus;
    QSqlQuery setlaststatus;

    setusustatus.prepare("UPDATE usu_usuario SET usu_status = ? WHERE usu_login = ?");
    setusustatus.addBindValue(status);
    setusustatus.addBindValue(login);
    setusustatus.exec();

    if(status != 0)
    {
       setlaststatus.prepare("UPDATE usu_usuario SET usu_laststatus = ? WHERE usu_login = ?");
       setlaststatus.addBindValue(status);
       setlaststatus.addBindValue(login);
       setlaststatus.exec();
       qDebug()<<"Last Status tambem foi atualizado";
    }


    if (!setusustatus.isActive())
    {
        qDebug() << "Error"  << setusustatus.lastError().text();
        Qerror = Qesetstatusfail;
        return false;
    }
    else
    {
         if(setusustatus.numRowsAffected() > 0)
         {
           qDebug() << "Novo Status setado";
           return true;
         }

         else
         {
             qDebug() << "Usuario nao encontrado";
             Qerror = Qesetstatusfail;
             return false;
         }
     }
}

int JagunDb::getUsuStatus(QString login)
{
    QSqlQuery getusustatus;

    QString userLogin;
    int status;

    getusustatus.prepare("SELECT usu_login, usu_status FROM usu_usuario WHERE usu_login = ?");
    getusustatus.addBindValue(login);
    getusustatus.exec();
    if (!getusustatus.isActive())
    {
        qDebug() << "Error"  << getusustatus.lastError().text();
        Qerror = Qesetidfail;
        return -10;
    }
    else
    {

        getusustatus.next();
        userLogin = getusustatus.value(0).toString();
        status = getusustatus.value(1).toInt();
        if(login == userLogin)
        {
           qDebug() << "Retornando id do usuario";
           return status;
        }
        else
        {
           qDebug() << "Usuario non ecxiste";
           return -10;
        }
    }
}

bool JagunDb::setUsuImage(QString login, QString imagem)
{
    QSqlQuery setusuimage;

    setusuimage.prepare("UPDATE usu_usuario SET usu_imagem = ? WHERE usu_login = ?");
    setusuimage.addBindValue(imagem);
    setusuimage.addBindValue(login);
    setusuimage.exec();
    if (!setusuimage.isActive())
    {
        qDebug() << "Error"  << setusuimage.lastError().text();
        Qerror = Qesetimagefail;
        return false;
    }
    else
    {
         if(setusuimage.numRowsAffected() > 0)
         {
           qDebug() << "Nova Imagem setada";
           return true;
         }

         else
         {
           qDebug() << "Usuario nao encontrado";
           Qerror = Qesetimagefail;
           return false;
         }
     }
}


QString JagunDb::getUsuImage(QString login)
{
    QSqlQuery getusuimage;

    QString userLogin;
    QString imagem;

    getusuimage.prepare("SELECT usu_login, usu_imagem FROM usu_usuario WHERE usu_login = ?");
    getusuimage.addBindValue(login);
    getusuimage.exec();
    if (!getusuimage.isActive())
    {
        qDebug() << "Error"  << getusuimage.lastError().text();
        Qerror = Qegetnickfail;
        return 0;
    }
    else
    {

        getusuimage.next();
        userLogin = getusuimage.value(0).toString();
        imagem = getusuimage.value(1).toString();
        if(login == userLogin)
        {
           qDebug() << "Retornando imagem do usuario";
           return imagem;
        }
        else
        {
           qDebug() << "Usuario non ecxiste";
           Qerror = Qegetnickfail;
           return 0;
        }
    }
}


bool JagunDb::setUsuMensagem(QString login, QString mensagem)
{
    QSqlQuery setmensagemquery;

    setmensagemquery.prepare("UPDATE usu_usuario SET usu_mensagem = ? WHERE usu_login = ?");
    setmensagemquery.addBindValue(mensagem);
    setmensagemquery.addBindValue(login);
    setmensagemquery.exec();
    if (!setmensagemquery.isActive())
    {
        qDebug() << "Error"  << setmensagemquery.lastError().text();
        Qerror = Qesetimagefail;
        return false;
    }
    else
    {
         if(setmensagemquery.numRowsAffected() > 0)
         {
           qDebug() << "Nova Mensagem Pessoal setada";
           return true;
         }

         else
         {
           qDebug() << "Usuario nao encontrado";
           Qerror = Qesetimagefail;
           return false;
         }
     }
}


QString JagunDb::getUsuMensagem(QString login)
{
    QSqlQuery getmensagemquery;

    QString userLogin;
    QString mensagem;

    getmensagemquery.prepare("SELECT usu_login, usu_mensagem FROM usu_usuario WHERE usu_login = ?");
    getmensagemquery.addBindValue(login);
    getmensagemquery.exec();
    if (!getmensagemquery.isActive())
    {
        qDebug() << "Error"  << getmensagemquery.lastError().text();
        Qerror = Qegetnickfail;
        return 0;
    }
    else
    {

        getmensagemquery.next();
        userLogin = getmensagemquery.value(0).toString();
        mensagem = getmensagemquery.value(1).toString();
        if(login == userLogin)
        {
           qDebug() << "Retornando Mensagem do usuario";
           return mensagem;
        }
        else
        {
           qDebug() << "Usuario non ecxiste";
           Qerror = Qegetnickfail;
           return 0;
        }
    }
}

QString JagunDb::getAddMsg(QString login, QString login2)
{
    QSqlQuery getaddmsgquery;

    QString msg;


    getaddmsgquery.prepare("SELECT lsc_mensagem FROM lsc_listcont WHERE usu_login1 = ? AND usu_login2 = ?");
    getaddmsgquery.addBindValue(login);
    getaddmsgquery.addBindValue(login2);
    getaddmsgquery.exec();
    if (!getaddmsgquery.isActive())
    {
        qDebug() << "Error"  << getaddmsgquery.lastError().text();
        Qerror = Qegetnickfail;
        return 0;
    }
    else
    {

        getaddmsgquery.next();
        msg = getaddmsgquery.value(0).toString();
        if(msg != "")
        {
           qDebug() << "Retornando Mensagem do usuario";
           return msg;
        }
        else
        {
           qDebug() << "nao existe mensagem";
           Qerror = Qegetnickfail;
           return 0;
        }
    }

}

bool JagunDb::acceptContact(QString login, QString login2)
{

    QSqlQuery acccontquery;
    QSqlQuery acccontquery2;

    acccontquery.prepare("UPDATE lsc_listcont SET lsc_status = ? WHERE usu_login1 = ? AND usu_login2 = ?");
    acccontquery.addBindValue(1);
    acccontquery.addBindValue(login);
    acccontquery.addBindValue(login2);
    acccontquery.exec();

    acccontquery2.prepare("UPDATE lsc_listcont SET lsc_status = ? WHERE usu_login1 = ? AND usu_login2 = ?");
    acccontquery2.addBindValue(1);
    acccontquery2.addBindValue(login2);
    acccontquery2.addBindValue(login);
    acccontquery2.exec();

    if(acccontquery.numRowsAffected() > 0 && acccontquery2.numRowsAffected() >0 )
    {
      qDebug() << "Agora eles realmente sao amigos";
      return true;
    }

    else
    {
      qDebug() << "Usuarios nao encontrados";
      Qerror = Qesetimagefail;
      return false;
    }

}


bool JagunDb::dontAccept(QString login, QString login2)
{
    QSqlQuery dontaccpquery;
    QSqlQuery dontaccpquery2;

    dontaccpquery.prepare("DELETE FROM lsc_listcont WHERE usu_login1 = ? AND usu_login2 = ?");
    dontaccpquery.addBindValue(login);
    dontaccpquery.addBindValue(login2);
    dontaccpquery.exec();

    dontaccpquery2.prepare("DELETE FROM lsc_listcont WHERE usu_login1 = ? AND usu_login2 = ?");
    dontaccpquery2.addBindValue(login2);
    dontaccpquery2.addBindValue(login);
    dontaccpquery2.exec();

    if (!dontaccpquery.isActive() && dontaccpquery2.isActive())
    {
        qDebug() << "Error"  << dontaccpquery.lastError().text();
        qDebug() << "Error"  << dontaccpquery2.lastError().text();
        Qerror = Qegetnickfail;
        return false;
    }

    else
    {
       if(dontaccpquery.numRowsAffected() > 0 && dontaccpquery2.numRowsAffected() >0 )
       {
          qDebug() << "AHH agora eles nao sao mais amigos";
          return true;
       }
       else
       {
          qDebug() << "Usuarios nao encontrados";
          Qerror = Qesetimagefail;
          return false;
       }
    }

}

QList< QPair <QString,QString > > JagunDb::getUnconCont(QString login)
{
        QSqlQuery unconfirmedquery;
        QString usu_login1;
        QString usu_login2;
        QList< QPair <QString,QString > > list;
        QPair<QString, QString> pair;

        unconfirmedquery.prepare("SELECT usu_login1, usu_login2 FROM lsc_listcont WHERE lsc_status = ?  AND usu_login2 = ? AND lsc_mensagem IS NOT NULL ");
        unconfirmedquery.addBindValue(0);
        unconfirmedquery.addBindValue(login);

        unconfirmedquery.exec();

        if (!unconfirmedquery.isActive())
        {
            qDebug() << "Error"  << unconfirmedquery.lastError().text();
            Qerror = Qegetnickfail;
        }

        else
        {
           while( unconfirmedquery.next() ) //procura pelos usuarios
           {
               usu_login1 = unconfirmedquery.value(0).toString();
               usu_login2 = unconfirmedquery.value(1).toString();
               pair.first = usu_login1;
               pair.second = usu_login2;
               list << pair;

           }
           return list;
        }
}




