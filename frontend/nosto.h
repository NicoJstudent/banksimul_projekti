#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>

namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    explicit nosto(QWidget *parent = nullptr);
    ~nosto();

    void setToken(const QByteArray &newToken);
    double amount;
    void setBalance(const double &newBalance);
    void setAccID(const QString &newAccID);

private slots:
    void withdrawClickedHandler();
    void customWithdrawClickedHandler();
    void cancelClickedHandler();


private:
    Ui::nosto *ui;
    double balance;
    QString accID;
    QByteArray token;
};

#endif // NOSTO_H
