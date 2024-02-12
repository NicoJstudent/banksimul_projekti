#ifndef BALANCE_H
#define BALANCE_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class balance;
}

class balance : public QDialog
{
    Q_OBJECT

public:
    explicit balance(QWidget *parent = nullptr);
    ~balance();

    void setBalance(const QString &newBalance);
    void setToken(const QByteArray &newToken);
    void setAccID(const QString &newAccID);

private slots:
    void returnClickedHandler();

private:
    Ui::balance *ui;
    QString myBalance;
    QByteArray token;
    QString accID;



};

#endif // BALANCE_H
