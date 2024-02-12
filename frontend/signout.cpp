#include "signout.h"
#include "ui_signout.h"

signout::signout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signout)
{
    ui->setupUi(this);
    this->showMaximized();

    connect(ui->BtnClose, SIGNAL(clicked()), this,
            SLOT(closeClickedHandler()));
}

signout::~signout()
{
    delete ui;
}

void signout::closeClickedHandler()
{
    this->close();
}
