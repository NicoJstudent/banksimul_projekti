#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "environment.h"


namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();


private slots:
    void numberClickedHandler();
    void clearAndSubmitClickedHandler();
    void backspaceClickedHandler();
    void loginSlot (QNetworkReply *reply);
    void cancelHandler();


private:
    Ui::login *ui;
    QString bankPIN;
    QString cardID;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
    QString accID;
};

#endif // LOGIN_H
