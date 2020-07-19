#ifndef CPUUSAGEINFO_H
#define CPUUSAGEINFO_H

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QTime>
#include <sstream>
#include <string>

class CPUUsageInfo : QObject {
    Q_OBJECT
   public:
    explicit CPUUsageInfo(QObject* parent = 0);
    QVector<double> getCPURate();
    bool refreshCPURate();
    void sleep(unsigned int msec);
    bool sampling(QVector<qint64>& idle, QVector<qint64>& total);

   signals:

   public slots:

   private:
    QFile file;
    QVector<double> cpuRate;
};

#endif  // CPUUSAGEINFO_H
