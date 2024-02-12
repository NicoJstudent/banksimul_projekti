#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    objectrfid= new Rfid;
    QString cardnumber = objectrfid -> cardreader();
    //qDebug() << "eeva" << cardnumber;
    ui -> labelResult -> setText(cardnumber);
    //QString myName = "Eeva R";
    //qDebug()<< myName ;
    //ui -> labelResult -> setText(myName);
    qDebug() << cardnumber;
}

