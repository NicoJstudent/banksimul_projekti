#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDateTime>

namespace Ui {
class confirmation;
}

class confirmation : public QDialog
{
    Q_OBJECT

public:
    explicit confirmation(QWidget *parent = nullptr);
    ~confirmation();
    void setAmount(const double &newAmount);
    void setBalance(const double &newBalance);
    void setAccID(const QString &newAccID);
    void setToken(const QByteArray &newToken);
    void logTransaction();

private:
    Ui::confirmation *ui;
    double amount;
    double balance;
    double newTotalAmount;
    QNetworkAccessManager *putManager;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString accID;
    QByteArray token;

private slots:
    void confirmClickedHandler();
    void cancelClickedHandler();
    void updateAccountSlot (QNetworkReply *reply);
    void addTransSlot (QNetworkReply *reply);

};

#endif // CONFIRMATION_H
