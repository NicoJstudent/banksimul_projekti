#include "transactions.h"
#include "mainmenu.h"
#include "ui_transactions.h"

transactions::transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transactions)
{
    ui->setupUi(this);
    this->showMaximized();

    connect(ui->cancel, SIGNAL(clicked()), this,
            SLOT(cancelClickedHandler()));
}

transactions::~transactions()
{
    delete ui;
}

void transactions::setTrans(const QString &newTrans)
{
    trans = newTrans;
    ui->textTran->setText(trans);
}

void transactions::setAccID(const QString &newAccID)
{
    accID = newAccID;
}

void transactions::setToken(const QByteArray &newToken)
{
    token = newToken;
}

void transactions::cancelClickedHandler()
{
    MainMenu *objectMenu=new MainMenu(this);
    objectMenu->setAccID(accID);
    objectMenu->setToken(token);
    objectMenu->open();
    this->close();
}
