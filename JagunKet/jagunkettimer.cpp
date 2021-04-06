#include "jagunkettimer.h"
#include <QDebug>

JagunKETTimer::JagunKETTimer(QObject *parent, uint maxCount) : QObject(parent)
{
    timer = new QTimer(this);
    currentCount       = 0;
    this->maxCount     = maxCount;
    connect(timer,SIGNAL(timeout()),this,SLOT(controlTimeout()));
}

void JagunKETTimer::startCounting()
{
    stopCounting();
    timer->start();
}

void JagunKETTimer::setIntervalCounting(uint msec)
{
    timer->setInterval((int) msec);
}

void JagunKETTimer::stopCounting()
{
    timer->stop();
    currentCount = 0;   
}

void JagunKETTimer::setMaxCount(uint maxCount)
{
    this->maxCount = maxCount;
}

void JagunKETTimer::controlTimeout()
{       
    if(currentCount < maxCount)
    {
        currentCount+=1;
        qDebug() << "JagunKETTimer:: Contador: " << currentCount << "/" << maxCount;
        emit alert();
    }
    else
    {
        stopCounting();
        emit finished();
    }
}

bool JagunKETTimer::isCounting()
{
    return timer->isActive();
}


