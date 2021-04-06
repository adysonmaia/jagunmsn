#ifndef JAGUNADDUSERDIALOG_H
#define JAGUNADDUSERDIALOG_H

#include "ui_jagunadduserdialog.h"

/**
 * Janela para adicionar novo usuario
 */
class JagunAddUserDialog : public QDialog, private Ui::JagunAddUserDialog {
    Q_OBJECT
    Q_DISABLE_COPY(JagunAddUserDialog)
public:
    explicit JagunAddUserDialog(QWidget *parent = 0);
    /**
     * recupera o nome de usuario digitado
     */
    QString getUser();
    /**
     * recupera a mensagem do usuario
     */
    QString getUserMessage();
private slots:
    /**
     * executado quando clicou em cancelar
     */
    void cancelUser();
    /**
     * executado quando clicou em adicionar
     */
    void addUser();
private:
    QString user;
    QString userMessage;
};

#endif // JAGUNADDUSERDIALOG_H
