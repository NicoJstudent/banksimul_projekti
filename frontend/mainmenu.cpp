#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "nosto.h"
#include "balance.h"
#include "environment.h"
#include "transactions.h"


MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->showMaximized();

    connect(ui->cancel, SIGNAL(clicked()), this,
            SLOT(cancelHandler()));
    connect(ui->withdraw, SIGNAL(clicked()), this,
            SLOT(withdrawHandler()));
    connect(ui->balance, SIGNAL(clicked()), this,
            SLOT(balanceHandler()));
    connect(ui->tran, SIGNAL(clicked()), this,
            SLOT(tranHandler()));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::cancelHandler()
{
    this->close();
}

void MainMenu::withdrawHandler()
{
    QString site_url=environment::getBaseUrl()+"/account/"+accID;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getDataManager = new QNetworkAccessManager(this);

    connect(getDataManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getWithdrawSlot(QNetworkReply*)));

    reply = getDataManager->get(request);
}

void MainMenu::getWithdrawSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    double bal;
    bal=json_obj["balance"].toDouble();

    nosto *objectnosto = new nosto(this);
    objectnosto->setBalance(bal);
    objectnosto->setAccID(accID);
    objectnosto->setToken(token);
    objectnosto->open();
    this->close();
}

void MainMenu::balanceHandler()
{
    QString site_url=environment::getBaseUrl()+"/account/"+accID;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getDataManager = new QNetworkAccessManager(this);

    connect(getDataManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getMyBalanceSlot(QNetworkReply*)));

    reply = getDataManager->get(request);

}

void MainMenu::getMyBalanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    double bal;
    bal=json_obj["balance"].toDouble();
    QString sBalance = QString::number(bal);

    balance *objectbalance = new balance(this);
    objectbalance->setBalance(sBalance+"€");
    objectbalance->setAccID(accID);
    objectbalance->setToken(token);
    objectbalance->open();
    this->close();
}


void MainMenu::tranHandler()
{
    QString site_url=environment::getBaseUrl()+"/transactions/";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getDataManager = new QNetworkAccessManager(this);

    connect(getDataManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getMyTranSlot(QNetworkReply*)));

    reply = getDataManager->get(request);
}


void MainMenu::getMyTranSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString tranData;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        tranData += QString::number(json_obj["amount"].toDouble())+" | "+json_obj["date_time"].toString()+" | "+json_obj["type"].toString()+"\r";
    }

    transactions *objectTran = new transactions(this);
    objectTran->setTrans(tranData);
    objectTran->setAccID(accID);
    objectTran->setToken(token);
    objectTran->open();
    this->close();

    reply->deleteLater();
    getDataManager->deleteLater();
}


void MainMenu::setToken(const QByteArray &newToken)
{
    token = newToken;
}

void MainMenu::setAccID(const QString &newAccID)
{
    accID = newAccID;
}

