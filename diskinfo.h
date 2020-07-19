#ifndef DISKINFO_H
#define DISKINFO_H

#include <QFile>
#include <QObject>
#include <QStorageInfo>

class diskInfo : public QObject {
    Q_OBJECT
   public:
    explicit diskInfo(QObject *parent = nullptr);

    QVector<QString> getDiskName();
    QVector<qint64> getDiskBytesTotal();
    QVector<qint64> getDiskBytesFree();
    QVector<qint64> getDiskBytesUsed();
    QVector<double> getDiskBytesRate();

   signals:

   public slots:

   private:
    QFile file;
    QVector<QString> diskName;
    QVector<qint64> diskBytesTotal;
    QVector<qint64> diskBytesFree;
    QVector<qint64> diskBytesUsed;
    QVector<double> diskBytesRate;
};

#endif  // DISKINFO_H
