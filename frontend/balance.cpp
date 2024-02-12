#include "balance.h"
#include "mainmenu.h"
#include "ui_balance.h"


balance::balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balance)
{
    ui->setupUi(this);
    this->showMaximized();
    
    connect(ui->Return, SIGNAL(clicked()),this,
            SLOT(returnClickedHandler()));

}

balance::~balance()
{
    delete ui;
}


void balance::returnClickedHandler()
{
    MainMenu *objectMenu=new MainMenu(this);
    objectMenu->setToken(token);
    objectMenu->setAccID(accID);
    objectMenu->open();
    this->close();
}


void balance::setBalance(const QString &newBalance)
{
    myBalance = newBalance;
    ui->Balance->setText(myBalance);
}

void balance::setToken(const QByteArray &newToken)
{
    token = newToken;
}

void balance::setAccID(const QString &newAccID)
{
    accID = newAccID;
}


