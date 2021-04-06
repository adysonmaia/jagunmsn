#include "jagunketfragmentsend.h"
#include <QDebug>

#include <QDebug>

JagunKETFragmentSend::JagunKETFragmentSend(QObject *parent) : QObject(parent)
{
    _data = 0;
    _sequential = 0;
    _confirmed = false;
    _timer = new JagunKETTimer(this);
    connect(_timer,SIGNAL(alert()),this,SLOT(alertTimer()));
    connect(_timer,SIGNAL(finished()),this,SLOT(finishedTimer()));
}

JagunKETFragmentSend::~JagunKETFragmentSend()
{
    if(_timer)
    {
        _timer->stopCounting();
        delete _timer;
    }

    if(_data)
        delete _data;
}

void JagunKETFragmentSend::setData(QByteArray & data, quint32 sequential)
{
    _timer->stopCounting();
    if(_data)
        delete _data;

    _data = new QByteArray(data);
    _sequential = sequential;
}

QByteArray & JagunKETFragmentSend::data() const
{
    return *_data;
}

void JagunKETFragmentSend::finishedTimer()
{
    if(!_confirmed) emit notConfirmedError(_sequential);
}

void JagunKETFragmentSend::alertTimer()
{
    if(!_confirmed) emit notConfirmed(_sequential);
}

void JagunKETFragmentSend::startWaitConfirmation(uint msec,uint count)
{
    // se o pacote ja foi confirmado nao e' necessario mais iniciar o timer
    if(_confirmed)
        return;

    _timer->stopCounting();
    _timer->setIntervalCounting(msec);
    _timer->setMaxCount(count);
    _timer->startCounting();
}

void JagunKETFragmentSend::setConfirmed(bool value)
{
    if(value)
    {
        _timer->stopCounting();
        //qDebug() << "JagunKETFragmentSend:: Sequencial: " << _sequential << " confirmado";
    }

    _confirmed = value;

}

bool JagunKETFragmentSend::confirmed()
{
    return _confirmed;
}

 bool JagunKETFragmentSend::isWaitingConfirmation()
 {
     return _timer->isCounting();
 }
