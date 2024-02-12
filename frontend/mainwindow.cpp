#include "mainwindow.h"
#include "login.h"
#include "mainmenu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();


    connect(ui->debit, SIGNAL(clicked()), this,
            SLOT(cardClickedHandler()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cardClickedHandler()
{
    login *objectlogin=new login(this);
    objectlogin->open();
}

