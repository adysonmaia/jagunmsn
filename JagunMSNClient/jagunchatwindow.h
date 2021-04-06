#ifndef JAGUNCHATWINDOW_H
#define JAGUNCHATWINDOW_H

#include "ui_jagunchatwindow.h"
#include <QtGui/QWidget>
#include <QtGui>



class JagunChatWindow : public QMainWindow, private Ui::JagunChatWindow {
    Q_OBJECT
    Q_DISABLE_COPY(JagunChatWindow)
public:
    explicit JagunChatWindow(QWidget *parent = 0);
    /**
     * seta a imagem do usuario principal
     */
    void setMainUserImagem(QString imageName);
    /**
     * adiciona um usuario a conversa
     */
    void addGuest(QString login, QString name,QString imageName, QString message, JagunMSNContact::ECStatus status);
    /**
     * Mostra a mensagem na tela de cima
     */
    void showMsg(QString from, QString msg);

    bool containsGuest(QStringList guests);
    void setStateGuest(QString login, QString name,QString imageName, QString message, JagunMSNContact::ECStatus status);

    void receiveMessage(QString loginFrom, QString message);

signals:
    /**
     * emite o sinal quando usuario digita algo
     */
    void sendMessage(QStringList to, QString message);
protected:
    virtual void changeEvent(QEvent *e);

private:
    QStringList loginGuest;
    QTextTableFormat table;
    void keyPressEvent(QKeyEvent *e);



private slots:
    void sendMsg();
signals:
    void pressEnter();


};

#endif // JAGUNCHATWINDOW_H
