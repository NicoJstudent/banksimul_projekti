#ifndef RFID_H
#define RFID_H
#include <QtSerialPort/QtSerialPort>
#include "rfid_global.h"
#include <QObject>

class RFID_EXPORT Rfid:public QObject
{
    Q_OBJECT
public:
    Rfid();
private:
    QSerialPort *serial;
    QString cardnumber;
public slots:
    QString cardreader();
    QString Number(){return cardnumber;}  //getter

signals:
    void cardready();
};

#endif // RFID_H
