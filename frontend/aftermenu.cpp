#include "aftermenu.h"
#include "mainmenu.h"
#include "signout.h"
#include "ui_aftermenu.h"

afterMenu::afterMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterMenu)
{
    ui->setupUi(this);
    this->showMaximized();

    connect(ui->close, SIGNAL(clicked()), this,
            SLOT(closeClickedHandler()));

}

afterMenu::~afterMenu()
{
    delete ui;
}

void afterMenu::closeClickedHandler()
{
    signout *objectOut=new signout(this);
    objectOut->open();
    this->close();
}


