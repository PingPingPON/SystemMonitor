#ifndef NETUSAGEINFO_H
#define NETUSAGEINFO_H

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QTime>
#include <sstream>
#include <string>

class NetUsageInfo : public QObject {
    Q_OBJECT
   public:
    explicit NetUsageInfo(QObject* parent = nullptr);
    QVector<QString> getName();
    QVector<double> getTransmitData();
    QVector<double> getReceiveData();

    bool refreshNetData();
    void sleep(unsigned int msec);
    bool sampling(QVector<qint64>& receives, QVector<qint64>& transmit);

   signals:
   public slots:

   private:
    QFile file;
    QVector<QString> names;
    QVector<double> receives;
    QVector<double> transmits;
};

#endif  // NETUSAGEINFO_H
