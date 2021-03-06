#include "jagunket.h"
#include "jagunpackageinformation.h"

JagunKET::JagunKET(QObject *parent) : QObject(parent)
{   
    connect(this,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(setState(QAbstractSocket::SocketState)));
    emit stateChanged(QAbstractSocket::UnconnectedState);

    udpSocket                     = 0;
    receiveController             = 0;
    sendController                = 0;
    portHost                      = 0;
    idConnection                  = 0;

    timerNewConnection  = new JagunKETTimer(this,MAX_TRY_ATTEMPTS_NEW_CONNECTION);
    timerNewConnection->setIntervalCounting(TIMER_INTERVAL_NEW_CONNECTION);

    timerCloseConnection = new JagunKETTimer(this,MAX_TRY_ATTEMPTS_CLOSE_CONNECTION);
    timerCloseConnection->setIntervalCounting(TIMER_INTERVAL_CLOSE_CONNECTION);

    connect(timerNewConnection,SIGNAL(alert()),this,SLOT(tryConnect()));
    connect(timerNewConnection,SIGNAL(finished()),this,SLOT(checkStateNewConnection()));
    connect(timerCloseConnection,SIGNAL(alert()),this, SLOT(tryCloseConnection()));
    connect(timerCloseConnection,SIGNAL(finished()),this,SLOT(clean()));

    qDebug() << "JagunKET:: Novo Socket Criado";
}

JagunKET::~JagunKET()
{
    delete timerNewConnection;
    delete timerCloseConnection;
    bufferMessages.clear();
    clean();

}

QAbstractSocket::SocketState JagunKET::getState() const
{
    return state;
}


void JagunKET::setState(QAbstractSocket::SocketState newState)
{
    QAbstractSocket::SocketState oldState = state;
    state = newState;

    if(state == QAbstractSocket::ConnectingState)
    {
        qDebug() << "JagunKET:: Estado - Conectando ao destinatario";
        return;
    }

    if(state == QAbstractSocket::ConnectedState)
    {
        timerNewConnection->stopCounting();
        qDebug() << "JagunKET:: Estado - Conectado ao destinatario";
        emit connected();
        return;
    }

    if(state == QAbstractSocket::UnconnectedState)
    {
        qDebug() << "JagunKET:: Estado - Desconectado";
        if(oldState == QAbstractSocket::ClosingState)
        {
            clean();
            emit disconnected();
        }
        return;
    }

    if(state == QAbstractSocket::ClosingState)
    {
        qDebug() << "JagunKET:: Estado - Desconectando do destinatario";
        return;
    }
}

void JagunKET::connectToHost(const QHostAddress & address, quint16 port)
{
    switch (state)
    {
        case QAbstractSocket::UnconnectedState:
            break;

        case QAbstractSocket::ConnectedState:
            qDebug() <<"JagunKET:: Ja existe uma conexao ativa";
            emit warning(EWJKOtherActiveConnection);
            return;
        case QAbstractSocket::ClosingState:
            emit warning(EWJKConnectInClosing);
        case QAbstractSocket::ConnectingState:
        default:
            return;
    }

    // primeira vez que tenta conectar, entao cria o socket udp
    if(!udpSocket)
    {
        qDebug() << "JagunKET:: criado socket UDP";
        udpSocket = new QUdpSocket(this);
        connect(udpSocket, SIGNAL(readyRead()), this, SLOT(arrivedDatagram()));

        // tenta criar uma porta para escuta
        if(!udpSocket->bind())
        {
            qDebug() << "JagunKET:: Nao existe porta disponivel";
            emit error(EEJKPortNotAvailable);
            return;
        }
    }

    emit stateChanged(QAbstractSocket::ConnectingState);
    addressHost = address;
    portHost    = port;
    tryConnect();
    timerNewConnection->startCounting();

    //qDebug() << "JagunKET:: Escutando a porta: " << udpSocket->localPort();
    //qDebug() << "JagunKET:: Enviando Pacote do tipo : " << JagunPackageInformation::getLiteralTypePackage(JagunPackageInformation::ETPNewConnection);
    //qDebug() << "JagunKET:: Enviando Para : " << addressHost << " Porta: " << portHost;

}

void JagunKET::checkStateNewConnection()
{
    if(state != QAbstractSocket::ConnectedState)
    {
        qDebug() << "JagunKET:: Erro - Impossivel criar nova conexao";
        emit stateChanged(QAbstractSocket::UnconnectedState);
        emit error(EEJKServerNotResponse);
    }
}

void JagunKET::tryConnect()
{
    if(state == QAbstractSocket::ConnectingState)
    {
        QByteArray datagram;
        QDataStream out(&datagram, QIODevice::WriteOnly);
        out << (quint8) JagunPackageInformation::ETPNewConnection;

        udpSocket->writeDatagram(datagram,addressHost,portHost);
    }
}



void JagunKET::arrivedDatagram()
{
    if(state == QAbstractSocket::UnconnectedState)
    {
        qDebug() << "JagunKET:: Pacote recebido mas ignorado. Motivo: Nao foi estabelecido uma conexao oficial como o destinatario";
        return;
    }

    QHostAddress address;
    quint16 port;
    QByteArray *datagram = new QByteArray();

    datagram->resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(datagram->data(), datagram->size(),&address, &port);

    if(address != addressHost || port != portHost)
    {
        qDebug() << "JagunKET:: Pacote recebido mas ignorado. Motivo: remetente desconhecido";
        delete datagram;
        return;
    }

    processDatagram(datagram);

}

void JagunKET::processDatagram(QByteArray *datagram)
{
    QDataStream in(datagram, QIODevice::ReadOnly);
    quint8 typePackage;
    in >> typePackage;
    switch (typePackage)
    {
        case(JagunPackageInformation::ETPNewConnection):
            qDebug() << "JagunKET:: Pacote recebido incorreto. Tipo: " << JagunPackageInformation::getLiteralTypePackage(typePackage);
            delete datagram;
            return;

        case(JagunPackageInformation::ETPConnectionEstablished):
            qDebug() << "JagunKET:: Pacote recebido. Tipo: " << JagunPackageInformation::getLiteralTypePackage(typePackage);
            if(state != QAbstractSocket::ConnectingState)
            {
                qDebug() << "JagunKET:: Ja existe uma conexao aberta";
                delete datagram;
                return;
            }
            quint32 id;
            in >> id;
            if(id <= 0)
            {
                qDebug() << "JagunKET:: Id invalido: " << id;
                delete datagram;
                return;
            }
            else
            {
                qDebug() << "JagunKET:: Id da conexao: " << id;
            }
            delete datagram;
            idConnection = id;

            //cria controladores
            sendController    = new JagunKETSendController(this,udpSocket, addressHost, portHost, idConnection);
            receiveController = new JagunKETReceiveController(this,udpSocket, addressHost, portHost, idConnection);
            connect(sendController,SIGNAL(sendSuccess()),this,SLOT(sendSuccess()));
            connect(sendController,SIGNAL(sendSuccess()),this,SIGNAL(sentData()));
            connect(sendController,SIGNAL(sendFailure(QByteArray*)),this,SLOT(sendFailure(QByteArray*)));
            connect(receiveController,SIGNAL(receiveSuccess(QByteArray*)),this,SIGNAL(receive(QByteArray*)));
            connect(receiveController,SIGNAL(receiveFailure()),this,SLOT(receiveFailure()));

            emit stateChanged(QAbstractSocket::ConnectedState);
            break;


        case(JagunPackageInformation::ETPConfirmationData) :
            sendController->receiveConfirmationData(datagram);
            break;
        case(JagunPackageInformation::ETPNewData):
            receiveController->receiveDatagram(datagram);
            break;
        case(JagunPackageInformation::ETPData):
            receiveController->receiveDatagram(datagram);
            break;
        case(JagunPackageInformation::ETPEndData):
            receiveController->receiveDatagram(datagram);
            break;
        case(JagunPackageInformation::ETPConnectionClosed):
            delete datagram;
            emit idAvailable(idConnection);
            clean();
            emit disconnected();
            break;
        default:
            delete datagram;
            qDebug() << "JagunKET:: Pacote recebido incorreto. Tipo: " << JagunPackageInformation::getLiteralTypePackage(typePackage);
            break;
    }
}

void JagunKET::send(QByteArray * data)
{
    QByteArray *dataSend = new QByteArray(*data);
    switch (state)
    {

        case QAbstractSocket::ConnectedState:
            break;

        case QAbstractSocket::ClosingState :
        case QAbstractSocket::UnconnectedState :
        case QAbstractSocket::ConnectingState :
        default:
            qDebug() << "JagunKET:: Nao foi possivel enviar o dado : sem conexao";
            emit warning(EWJKNotConnected);
            return;
    }

    if(bufferMessages.length() == MAX_BUFFER)
    {
        qDebug() << "JagunKET:: Nao foi possivel enviar o dado : buffer cheio";
        emit warning(EWJKFullBufferMessages);
        return;
    }
    bufferMessages << dataSend;
    trySend();
}

void JagunKET::trySend()
{
    if (!sendController->stillSending() && !bufferMessages.isEmpty()) {
        QByteArray* data;
        data = bufferMessages.takeFirst();
        sendController->send(data);
    }
}

void JagunKET::sendSuccess()
{
    trySend();
}

void JagunKET::sendFailure(QByteArray *data)
{
    qDebug() << "JagunKET:: Nao conseguiu enviar um dado";
    emit error(EEJKSendData);
    clean();
}


void JagunKET::receiveFailure()
{
    qDebug() << "JagunKET:: Nao conseguiu receber um dado completo";
    emit error(EEJKReceiveData);
    clean();
}


void JagunKET::close()
{
    switch (state)
    {
        case QAbstractSocket::ClosingState:
            qDebug() << "JagunKET:: Conexao ja esta sendo fechada";
            emit warning(EWJKCloseInClosing);
            return;
        case QAbstractSocket::UnconnectedState:
            qDebug() << "JagunKET:: Nao existe conexao ativa para ser fechada";
            emit warning(EWJKCloseInUnconnected);
            return;
        case QAbstractSocket::ConnectedState:
            break;
        case QAbstractSocket::ConnectingState:
            qDebug() << "JagunKET:: Nao e' possivel fechar a conexao pois ainda esta conectando";
            emit warning(EWJKCloseInConnecting);
            return;
        default:
            return;
    }

    timerCloseConnection->startCounting();
    emit stateChanged(QAbstractSocket::ClosingState);
}

void JagunKET::tryCloseConnection()
{

    qDebug() << "JagunKET:: Tentando fechar conexao " << JagunPackageInformation::getLiteralTypePackage(state);

    if(state == QAbstractSocket::ClosingState &&
        !sendController->stillSending() && !receiveController->stillReceiving() &&
        bufferMessages.isEmpty()
      )
    {
        qDebug() << "JagunKET:: Fechando";
        timerCloseConnection->stopCounting();

        QByteArray datagram;
        QDataStream out(&datagram,QIODevice::WriteOnly);
        out << (quint8) JagunPackageInformation::ETPConnectionClosed;
        out << idConnection;
        udpSocket->writeDatagram(datagram,addressHost,portHost);
        clean();
    }
}

void JagunKET::clean()
{
    if(udpSocket)
    {
        udpSocket->abort();
        delete udpSocket;
    }

    udpSocket                     = 0;
    emit stateChanged(QAbstractSocket::UnconnectedState);
    if(receiveController)
    {
        delete receiveController;
    }
    receiveController             = 0;
    if(sendController)
    {
        delete sendController;
    }
    sendController                = 0;
    portHost                      = 0;
    idConnection                  = 0;
}
