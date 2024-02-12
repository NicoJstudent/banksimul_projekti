#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    void setToken(const QByteArray &newToken);
    void setAccID(const QString &newAccID);

private slots:
    void cancelHandler();
    void withdrawHandler();
    void balanceHandler();
    void tranHandler();
    void getMyBalanceSlot (QNetworkReply *reply);
    void getMyTranSlot (QNetworkReply *reply);
    void getWithdrawSlot (QNetworkReply *reply);

private:
    Ui::MainMenu *ui;
    QByteArray token;
    QString accID;
    QNetworkAccessManager *getDataManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // MAINMENU_H
