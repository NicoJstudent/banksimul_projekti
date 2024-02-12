#ifndef AFTERMENU_H
#define AFTERMENU_H

#include <QDialog>

namespace Ui {
class afterMenu;
}

class afterMenu : public QDialog
{
    Q_OBJECT

public:
    explicit afterMenu(QWidget *parent = nullptr);
    ~afterMenu();

private:
    Ui::afterMenu *ui;

private slots:
    void closeClickedHandler();

};

#endif // AFTERMENU_H
