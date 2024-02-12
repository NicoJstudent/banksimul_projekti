#include "confirmation.h"
#include "aftermenu.h"
#include "mainmenu.h"
#include "ui_confirmation.h"
#include "environment.h"

confirmation::confirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirmation)
{
    ui->setupUi(this);
    this->showMaximized();

    connect(ui->cancel, SIGNAL(clicked()), this,
            SLOT(cancelClickedHandler()));
    connect(ui->confirm, SIGNAL(clicked()), this,
            SLOT(confirmClickedHandler()));

}

confirmation::~confirmation()
{
    delete ui;
}

void confirmation::setAmount(const double &newAmount)
{
    amount = newAmount;
    QString eventAmount = QString::number(amount);
    ui->event->setText(eventAmount+"€");
}

void confirmation::setBalance(const double &newBalance)
{
    balance = newBalance;
}

void confirmation::setAccID(const QString &newAccID)
{
    accID = newAccID;
}

void confirmation::setToken(const QByteArray &newToken)
{
    token = newToken;
}

void confirmation::logTransaction()
{
    QDateTime date = QDateTime::currentDateTime();
    QString strTime = date.toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<strTime;

    QJsonObject jsonObj;
    jsonObj.insert("amount", amount);
    jsonObj.insert("date_time", strTime);
    jsonObj.insert("type","Nosto");
    jsonObj.insert("Account_idAccount", accID);

    QString site_url=environment::getBaseUrl()+"/transactions";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    qDebug()<<"Transaction saved";
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(addTransSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}


void confirmation::confirmClickedHandler()
{
    newTotalAmount = balance - amount;
    if(newTotalAmount<0){

        ui->event->setText("Katevaraus ei riitä");
        qDebug()<<("Katevaraus ei riitä");

    }
    else {

        QJsonObject jsonObj;
        //jsonObj.insert("idAccount",accID);
        jsonObj.insert("balance",newTotalAmount);
        jsonObj.insert("debit_limit",0);

        QString site_url=environment::getBaseUrl()+"/account/"+accID;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        qDebug()<<"Tilin ID:"<<accID;
        //WEBTOKEN ALKU
        request.setRawHeader(QByteArray("Authorization"),(token));
        //WEBTOKEN LOPPU

        putManager = new QNetworkAccessManager(this);
        connect(putManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateAccountSlot(QNetworkReply*)));
        reply = putManager->put(request, QJsonDocument(jsonObj).toJson());

        logTransaction();

        afterMenu *objectAfter=new afterMenu(this);
        objectAfter->open();
        this->close();
    }

}

void confirmation::cancelClickedHandler()
{
    MainMenu *objectMenu=new MainMenu(this);
    objectMenu->setAccID(accID);
    objectMenu->setToken(token);
    objectMenu->open();
    this->close();
}

void confirmation::updateAccountSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    putManager->deleteLater();
}

void confirmation::addTransSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
}
