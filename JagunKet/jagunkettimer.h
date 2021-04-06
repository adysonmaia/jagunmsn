#ifndef JAGUNKETTIMER_H
#define JAGUNKETTIMER_H

#include <QTimer>

class JagunKETTimer : public QObject
{
    Q_OBJECT
public:
    /**
     * Construtor
     */
    JagunKETTimer(QObject *parent = 0, uint maxCount = 0);
    /**
     * Inicia o timer
     */
    void startCounting();
    /**
     * Intervalo para timeout em milisegundos
     */
    void setIntervalCounting(uint msec);
    /**
     * Para o timer
     */
    void stopCounting();
    /**
     * Numero maximo de timeouts antes de disparar o sinal finished
     */
    void setMaxCount(uint maxCount);
    /**
     * Informa se o contador esta funcionando
     */
    bool isCounting();
private:
    // controla o numero maximo de vezes que o timeout pode ser chamado
    uint maxCount;
    // controla o numero de vezes que o timeout foi disparado
    uint currentCount;
    // timer para gerar eventos de timeout
    QTimer *timer;
private slots:
    /**
     * Gerencia as ocorrencias de timeout
     */
    void controlTimeout();
signals:
    /**
     * Sinal emitido depois que foi atingido numero maximo de ocorrencias de timeout
     */
    void finished();
    /**
     * Sinal emitido quando o numero de timeouts ocorridos e' menor que o maximo
     */
    void alert();

};

#endif // JAGUNKETTIMER_H
