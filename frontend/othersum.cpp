#include "othersum.h"
#include "confirmation.h"
#include "mainmenu.h"
#include "nosto.h"
#include "ui_othersum.h"

otherSum::otherSum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otherSum)
{
    ui->setupUi(this);
    this->showMaximized();

    connect(ui->N1, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N2, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N3, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N4, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N5, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N6, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N7, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N8, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N9, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));
    connect(ui->N0, SIGNAL(clicked()), this,
            SLOT(numberClickedHandler()));

    connect(ui->Clear, SIGNAL(clicked()), this,
            SLOT(clearAndSubmitClickedHandler()));
    connect(ui->Submit, SIGNAL(clicked()), this,
            SLOT(clearAndSubmitClickedHandler()));

    connect(ui->backspace, SIGNAL(clicked()), this,
            SLOT(backspaceClickedHandler()));

    connect(ui->Cancel, SIGNAL(clicked()), this,
            SLOT(cancelClickedHandler()));


}

otherSum::~otherSum()
{
    delete ui;
}

void otherSum::numberClickedHandler()
{
    QPushButton *button = (QPushButton *)sender();      //Pointteri numerosta mitä on painettu
    QString butVal = button->text();                    //Otetaan napin text() tieto napin arvoksi
    QString displayVal = ui->Sum->text();               //Tämän hetkinen teksti
    QString newVal = displayVal + butVal;               //Lisätään uusi numero vanhan tekstin perään

    ui->Sum->setText(newVal);                           //Päivitetään näkyvä teksti

}

void otherSum::clearAndSubmitClickedHandler()
{
    QPushButton *button = (QPushButton *)sender();      //Napin painalluksesta luodaan pointteri
    QString butVal = button->text();

    QString displayPin = ui->Sum->text();               //numerot stringiksi
    amount = displayPin.toDouble();
    qDebug()<<amount;

    if(QString::compare(butVal, "OK", Qt::CaseInsensitive) == 0){
        confirmation *objectCon=new confirmation(this);
        objectCon->setAccID(accID);
        objectCon->setToken(token);
        objectCon->setBalance(balance);
        objectCon->setAmount(amount);
        objectCon->open();
        this->close();

    }

    else if(QString::compare(butVal, "Clear", Qt::CaseInsensitive) == 0){
        ui->Sum->clear();

    }
}

void otherSum::backspaceClickedHandler()
{
    QString displayVal = ui->Sum->text();
    displayVal.chop(1);
    ui->Sum->setText(displayVal);

}

void otherSum::cancelClickedHandler()
{
    MainMenu *objectMain=new MainMenu(this);
    objectMain->setAccID(accID);
    objectMain->setToken(token);
    objectMain->open();
    this->close();
}

void otherSum::setBalance(const double &newBalance)
{
    balance = newBalance;
}

void otherSum::setAccID(const QString &newAccID)
{
    accID = newAccID;
}

void otherSum::setToken(const QByteArray &newToken)
{
    token = newToken;
}
