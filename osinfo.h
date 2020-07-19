//
// Created by dyf on 2020/7/4.
//

#ifndef OSINFO_H
#define OSINFO_H

#include <QFile>
#include <QObject>
#include <QtDebug>
#include <sstream>
class OSInfo : public QObject {
    Q_OBJECT
   public:
    explicit OSInfo(QObject *parent = 0);

    QVector<QString> getLoadAvg();

    QVector<QString> getTime();

   signals:

   public slots:

   private:
    QFile file;
};

#endif  // OSINFO_H
