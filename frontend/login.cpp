#include "login.h"
#include "mainmenu.h"
#include "ui_login.h"


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
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

    connect(ui->cancel, SIGNAL(clicked()), this,
            SLOT(cancelHandler()));
}

login::~login()
{
    delete ui;
}

void login::numberClickedHandler()
{
    QPushButton *button = (QPushButton *)sender();      //Pointteri numerosta mitä on painettu
    QString butVal = button->text();                    //Otetaan napin text() tieto napin arvoksi
    QString displayVal = ui->Pin->text();               //Tämän hetkinen teksti
    QString newVal = displayVal + butVal;               //Lisätään uusi numero vanhan tekstin perään

    ui->Pin->setText(newVal);

}

void login::clearAndSubmitClickedHandler()
{
    QPushButton *button = (QPushButton *)sender();      //Pointteri napista ja tarkistetaan myöhemmin
    QString butVal = button->text();                    //mitä painettu

    bankPIN = ui->Pin->text();
    cardID = "0600064207";                                //tähän kortin ID jostain

    if(cardID == "0600064207"){
        accID = "1";
    }else if(cardID == "06000D89B8"){
        accID = "2";
    }


    if(QString::compare(butVal, "OK", Qt::CaseInsensitive) == 0){

        QJsonObject jsonObj;
        jsonObj.insert("cardID",cardID);
        jsonObj.insert("bankPIN",bankPIN);

        QString site_url=environment::getBaseUrl()+"/login";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

        reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

    }

    else if(QString::compare(butVal, "Clear", Qt::CaseInsensitive) == 0){
        ui->Pin->clear();

    }
}

void login::backspaceClickedHandler()
{
    QString displayVal = ui->Pin->text();
    displayVal.chop(1);
    ui->Pin->setText(displayVal);

}

void login::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    if(QString::compare(response_data,"-4078")==0 || response_data.length()==0){
        ui->labelSignInfo->setText("Virhe tietokantayhteydessä");
    }
    else{
        if(QString::compare(response_data, "false")!=0){
            token="Bearer "+response_data;
            qDebug()<<token;
            qDebug()<<accID;            
            MainMenu *objectMenu=new MainMenu(this);
            objectMenu->setAccID(accID);
            objectMenu->setToken(token);
            objectMenu->open();
            this->close();
        }
        else {
           ui->labelSignInfo->setText("Väärä PIN");
           ui->Pin->clear();
        }
    }
    qDebug()<<response_data;
    reply->deleteLater();
    loginManager->deleteLater();
}

void login::cancelHandler()
{
    this->close();
}



