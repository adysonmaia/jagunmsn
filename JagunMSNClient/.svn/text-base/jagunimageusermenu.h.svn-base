#ifndef JAGUNIMAGEUSERMENU_H
#define JAGUNIMAGEUSERMENU_H

#include "ui_jagunimageusermenu.h"
#include <QDir>

/**
 * menu com as imagens do usuario
 */
class JagunImageUserMenu : public QWidget, private Ui::JagunImageUserMenu {
    Q_OBJECT
    Q_DISABLE_COPY(JagunImageUserMenu)

public:
    /**
     * Construtor
     */
    explicit JagunImageUserMenu(QWidget *parent = 0);
    /**
     * carregar as imagens do usuario a partir de um diretorio
     */
    void loadUserImages(const QDir & d);
    /**
     * retorna a imagem padrao ou seja se existe uma imagem com o nome default no diretorio
     */
    QIcon* defaultImage();
protected:
    virtual void changeEvent(QEvent *e);

private:
    /**
     * icone padrao do usuario
     */
    QIcon* _defaultImage;
private slots:
    /**
     * captura o evento quando o usuario escolhe uma imagem
     */
    void selectItem(QModelIndex i);
signals:
    /**
     * emitido quando o usuario escolhe uma nova imagem
     */
    void newImage(QIcon i,QString imageName);

};

#endif // JAGUNIMAGEUSERMENU_H
