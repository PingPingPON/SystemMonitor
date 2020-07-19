//
// Created by dyf on 2020/7/4.
//

#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QDebug>
#include <QFile>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QObject>
#include <QStorageInfo>
#include <QSysInfo>
#include <sstream>
#include <string>

class SystemInfo : public QObject {
    Q_OBJECT
   public:
    enum CPU { NAME = 0, KERNEL_NUM = 1, FREQ = 2, BUF_SIZE = 3 };

    explicit SystemInfo(QObject *parent = 0);

    QVector<QString> getDeviceInfo();

    QVector<QString> getCPUInfo();

    QVector<QString> getVersionInfo();

   signals:

   public slots:

   private:
    QFile file;
};

#endif  // SYSTEMINFO_H
