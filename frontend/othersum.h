#ifndef OTHERSUM_H
#define OTHERSUM_H

#include <QDialog>

namespace Ui {
class otherSum;
}

class otherSum : public QDialog
{
    Q_OBJECT

public:
    explicit otherSum(QWidget *parent = nullptr);
    ~otherSum();

    void setBalance(const double &newBalance);
    void setAccID(const QString &newAccID);
    void setToken(const QByteArray &newToken);

private:
    Ui::otherSum *ui;
    double amount;
    double balance;
    QString accID;
    QByteArray token;

private slots:
    void numberClickedHandler();
    void clearAndSubmitClickedHandler();
    void backspaceClickedHandler();
    void cancelClickedHandler();
};

#endif // OTHERSUM_H
