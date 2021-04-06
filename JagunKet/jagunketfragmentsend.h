#ifndef JAGUNKETFRAGMENTSEND_H
#define JAGUNKETFRAGMENTSEND_H

#include "jagunkettimer.h"
#include <QObject>
#include <QByteArray>

/**
 * Controla um pedaco de informacao para ser enviado pelo controlador de envio
 */
class JagunKETFragmentSend : public QObject
{
    Q_OBJECT
public:
    /**
     * Construtor
     */
    JagunKETFragmentSend(QObject *parent);
    /**
     * Destrutor
     */
    ~JagunKETFragmentSend();

    /**
     * Pedaco de dado armazenado
     * @param QByteArray Pedaco do dado
     * @param quint32 Sequencial do pedado do dado referente ao dado original (total)
     */
    void setData(QByteArray & data, quint32 sequential);
    /**
     * Pedaco de dado armazenado
     * @return QByteArray pedaco do dado
     */
    QByteArray & data() const;

    /**
     * inicia a epera pela confirmacao de que o dado foi recebido pelo destinatario
     * @param uint tempo de espera
     * @param uint numero de tentivas para esperar
     */
    void startWaitConfirmation(uint msec,uint count);
    /**
     * informa que o pacote foi recebido pelo destinatario
     */
    void setConfirmed(bool value);
    bool confirmed();

    /**
     * Informa se o timer foi iniciado e a classe espera pela confirmacao do pacote
     */
    bool isWaitingConfirmation();
private:
    // controle de tempo de espera de confirmacao do destinatario de que o pedaco foi recebido
    JagunKETTimer *_timer;
    // pedaco de dado armazeado
    QByteArray *_data;
    // sequencial do pedaco referente ao dado original
    quint32 _sequential;
    // indica se o dado ja foi recebido pelo destinatario
    bool _confirmed;

private slots:
    /**
     * executado quando o sinal finished do timer e' emitido
     */
    void finishedTimer();
    /**
     * executado quando o sinal alert do timer e' emitido
     */
    void alertTimer();
signals:
    /**
     * sinal de erro emitido quando a classe nao recebe confirmacao de que o dado foi recebido depois do timer ter emitido finished
     * @param quint32 sequencial do pedaco do dado
     */
    void notConfirmedError(quint32 sequential);
    /**
     * sinal emitido quando o timer gera um sinal de alert
     * @param quint32 sequencial do pedaco do dado
     */
    void notConfirmed(quint32 sequential);
};

#endif // JAGUNKETFRAGMENTSEND_H
