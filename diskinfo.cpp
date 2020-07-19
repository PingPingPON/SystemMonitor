#include "diskinfo.h"

diskInfo::diskInfo(QObject *parent) : QObject(parent) {
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
        diskName.append(storage.displayName());
        diskBytesTotal.append(storage.bytesTotal());
        diskBytesFree.append(storage.bytesFree());
        diskBytesUsed.append(diskBytesTotal.last() - diskBytesFree.last());
        diskBytesRate.append(((int)(100 * (1.0 * diskBytesUsed.last() /
                                           diskBytesTotal.last()))) /
                             100.0);
    }
}

QVector<QString> diskInfo::getDiskName() { return diskName; }

QVector<qint64> diskInfo::getDiskBytesTotal() { return diskBytesTotal; }

QVector<qint64> diskInfo::getDiskBytesFree() { return diskBytesFree; }

QVector<qint64> diskInfo::getDiskBytesUsed() { return diskBytesUsed; }

QVector<double> diskInfo::getDiskBytesRate() { return diskBytesRate; }
