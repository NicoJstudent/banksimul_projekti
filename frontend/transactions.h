#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>

namespace Ui {
class transactions;
}

class transactions : public QDialog
{
    Q_OBJECT

public:
    explicit transactions(QWidget *parent = nullptr);
    ~transactions();

    void setTrans(const QString &newTrans);
    void setAccID(const QString &newAccID);
    void setToken(const QByteArray &newToken);

private:
    Ui::transactions *ui;
    QString trans;
    QByteArray token;
    QString accID;

private slots:
    void cancelClickedHandler();

};

#endif // TRANSACTIONS_H
