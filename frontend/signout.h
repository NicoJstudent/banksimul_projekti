#ifndef SIGNOUT_H
#define SIGNOUT_H

#include <QDialog>

namespace Ui {
class signout;
}

class signout : public QDialog
{
    Q_OBJECT

public:
    explicit signout(QWidget *parent = nullptr);
    ~signout();

private:
    Ui::signout *ui;

private slots:
    void closeClickedHandler();
};

#endif // SIGNOUT_H
