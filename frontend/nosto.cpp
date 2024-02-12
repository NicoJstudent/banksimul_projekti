#include "nosto.h"
#include "confirmation.h"
#include "othersum.h"
#include "ui_nosto.h"
#include "mainmenu.h"

nosto::nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);
    this->showMaximized();

    connect(ui->cancel, SIGNAL(clicked()), this,
            SLOT(cancelClickedHandler()));
    connect(ui->withrCustom, SIGNAL(clicked()), this,
            SLOT(customWithdrawClickedHandler()));
    connect(ui->withr20, SIGNAL(clicked()), this,
            SLOT(withdrawClickedHandler()));
    connect(ui->withr40, SIGNAL(clicked()), this,
            SLOT(withdrawClickedHandler()));
    connect(ui->withr60, SIGNAL(clicked()), this,
            SLOT(withdrawClickedHandler()));
    connect(ui->withr100, SIGNAL(clicked()), this,
            SLOT(withdrawClickedHandler()));
    connect(ui->withr150, SIGNAL(clicked()), this,
            SLOT(withdrawClickedHandler()));
    connect(ui->withr200, SIGNAL(clicked()), this,
            SLOT(withdrawClickedHandler()));


}

nosto::~nosto()
{
    delete ui;
}

void nosto::setToken(const QByteArray &newToken)
{
    token = newToken;
}

void nosto::setBalance(const double &newBalance)
{
    balance = newBalance;
    qDebug()<<"Balance:";
    qDebug()<<balance;
}

void nosto::setAccID(const QString &newAccID)
{
    accID = newAccID;
}

void nosto::withdrawClickedHandler()
{
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    butVal.chop(2);
    amount = butVal.toDouble();
    qDebug()<<amount;

    confirmation *objectCon=new confirmation(this);
    objectCon->setAmount(amount);
    objectCon->setBalance(balance);
    objectCon->setToken(token);
    objectCon->setAccID(accID);
    objectCon->open();

    this->close();
}

void nosto::customWithdrawClickedHandler()
{
    otherSum *objectSum=new otherSum(this);
    objectSum->setAccID(accID);
    objectSum->setBalance(balance);
    objectSum->setToken(token);
    objectSum->open();
    this->close();

}

void nosto::cancelClickedHandler()
{
    MainMenu *objectMenu=new MainMenu(this);
    objectMenu->setAccID(accID);
    objectMenu->setToken(token);
    objectMenu->open();
    this->close();
}

