#include "jagunimageusermenu.h"
#include <QListWidgetItem>
#include <QDebug>

JagunImageUserMenu::JagunImageUserMenu(QWidget *parent) :
    QWidget(parent){
    setupUi(this);
    _defaultImage = 0;
    connect(listWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(selectItem(QModelIndex)));
}

void JagunImageUserMenu::loadUserImages(const QDir & d)
{
   /**
    * exemplo de entrada passando um diretorio de recurso
    * QDir d(":/user/resource/user");
    */

   QFileInfoList files = d.entryInfoList();
   QIcon *icon = 0;
   foreach(QFileInfo file,files)
   {
       icon = new QIcon(file.filePath());
       if(file.baseName() == "default")
       {
           _defaultImage = icon;
       }
       QListWidgetItem *item = new QListWidgetItem(listWidget);
       item->setIcon(*icon);
       item->setData(Qt::UserRole,file.baseName());
   }
}

QIcon * JagunImageUserMenu::defaultImage()
{
    return _defaultImage;
}

void JagunImageUserMenu::selectItem(QModelIndex i)
{
    emit newImage(listWidget->currentItem()->icon(),qVariantValue<QString>(listWidget->currentItem()->data(Qt::UserRole)));
}

void JagunImageUserMenu::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}
