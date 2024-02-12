#include "rfid.h"
#include "qdebug.h"
#include <iostream>

Rfid::Rfid()
{
  serial = new QSerialPort;

  serial->setPortName("com3");

  qDebug() << serial->portName();

  serial->setBaudRate(9600);

  serial->setDataBits(QSerialPort::Data8);

  serial->setParity(QSerialPort::NoParity);

  serial->setStopBits(QSerialPort::OneStop);

  serial->setFlowControl(QSerialPort::HardwareControl);

  serial->open(QIODevice::ReadWrite);
  connect (serial, SIGNAL(readyRead()),this, SLOT(cardreader()));
}

QString Rfid::cardreader()
{
    QString result = serial -> readAll();
    qDebug() << result;
    //emit cardready();

    QString cardNumber = serial -> readAll();
    qDebug() << cardnumber;
    return result;
}

