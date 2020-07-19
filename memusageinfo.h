#ifndef MEMUSAGEINFO_H
#define MEMUSAGEINFO_H

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QTime>
#include <QTimerEvent>
#include <sstream>
#include <string>

class memUsageInfo : public QObject {
    Q_OBJECT
   public:
    explicit memUsageInfo(QObject *parent = nullptr);
    QVector<double> getMemRate();
    QVector<int> getMemAll();

    bool refreshMemRate();

   signals:
   public slots:

   private:
    QFile file;
    double memRate;
    double swapRate;
    int swapAll;
    int memAll;
    int memAvailable;
    int swapAvailable;
};

#endif  // MEMUSAGEINFO_H
