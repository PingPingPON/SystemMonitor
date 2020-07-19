//
// Created by dyf on 2020/7/4.
//

#include "systeminfo.h"

SystemInfo::SystemInfo(QObject *parent) : QObject(parent) {}

QVector<QString> SystemInfo::getDeviceInfo() {
    QVector<QString> deviceInfo(6, "\0");
    // 获得本机名称
    deviceInfo[0] = QHostInfo::localHostName();
    QVector<QString> s;
    QVector<qint64> t;
    qint64 sum = 0;
    // 遍历挂载点，求出磁盘总容量
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
        s.push_back(storage.displayName());
        t.push_back(storage.bytesTotal());
        sum += storage.bytesTotal();
    }
    deviceInfo[1] = tr("%1").arg(sum);

    QHostInfo host = QHostInfo::fromName(QHostInfo::localHostName());
    if (host.error() != QHostInfo::NoError) {
        qDebug() << "Lookup failed:" << host.errorString();
        return deviceInfo;
    }

    foreach (const QHostAddress &address, host.addresses()) {
        // 输出IPV4、IPv6地址
        if (address.protocol() == QAbstractSocket::IPv4Protocol)
            deviceInfo[2] = address.toString();
        else if (address.protocol() == QAbstractSocket::IPv6Protocol)
            deviceInfo[3] = address.toString();
    }

    // 遍历所有网络接口，找出本地MAC
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface net, nets) {
        if (net.flags().testFlag(QNetworkInterface::IsUp) &&
            net.flags().testFlag(QNetworkInterface::IsRunning) &&
            !net.flags().testFlag(QNetworkInterface::IsLoopBack)) {
            deviceInfo[4] = net.hardwareAddress();
            break;
        }
    }

    QString tmpStr;
    char buf[1024];
    int f_pos;
    int res;
    int flag = 0;

    file.setFileName("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: can't open meminfo";
        return deviceInfo;
    }
    while (flag < 1) {
        res = file.readLine(buf, size_t(buf));
        if (res <= 0) break;
        tmpStr = QString(buf);
        if ((f_pos = tmpStr.indexOf("MemTotal")) != -1) {
            f_pos += 9;
            QString tmp = QString(tmpStr.mid(f_pos, tmpStr.length() - 10));
            std::string tmps = tmp.toStdString();
            std::stringstream ss;
            int t;

            ss << tmps;
            ss >> t;
            ss >> tmps;
            deviceInfo[5] =
                QString(QString::number(t) + QString::fromStdString(tmps));
            flag++;
        }
        file.close();
    }
    return deviceInfo;
}

QVector<QString> SystemInfo::getCPUInfo() {
    QVector<QString> cpuInfo(4, "\0");
    QString tmpStr;
    char buf[1024];
    int f_pos;
    int res;
    int flag = 0;

    file.setFileName("/proc/cpuinfo");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: can't open cpuinfo";
        return cpuInfo;
    }
    while (flag < 4) {
        res = file.readLine(buf, size_t(buf));
        if (res <= 0) {
            break;
        }
        tmpStr = QString(buf);
        if ((f_pos = tmpStr.indexOf("model name")) != -1) {
            f_pos += 13;
            cpuInfo[0] = QString(tmpStr.mid(f_pos, tmpStr.length() - 14));
            flag++;
        } else if ((f_pos = tmpStr.indexOf("cpu cores")) != -1) {
            f_pos += 12;
            cpuInfo[1] = QString(tmpStr.mid(f_pos, tmpStr.length() - 13));
            flag++;
        } else if ((f_pos = tmpStr.indexOf("cpu MHz")) != -1) {
            f_pos += 11;
            cpuInfo[2] = QString(tmpStr.mid(f_pos, tmpStr.length() - 12));
            flag++;
        } else if ((f_pos = tmpStr.indexOf("cache size")) != -1) {
            f_pos += 13;
            cpuInfo[3] = QString(tmpStr.mid(f_pos, tmpStr.length() - 14));
            flag++;
        }
    }
    file.close();

    return cpuInfo;
}

QVector<QString> SystemInfo::getVersionInfo() {
    QVector<QString> vInfo(4, "\0");
    QString tmpStr;
    char buf[1024];
    int res;

    file.setFileName("/proc/version");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: can't open version";
        return vInfo;
    }
    res = file.readLine(buf, sizeof(buf));
    if (res > 0) {
        tmpStr = QString(buf);
        int pos1 = tmpStr.indexOf("Linux version");
        int pos2 = tmpStr.indexOf(" (");
        vInfo[0] = QString(tmpStr.mid(pos1, pos2 - pos1));

        pos1 = tmpStr.indexOf("gcc version");
        pos2 = tmpStr.indexOf("))") + 1;
        vInfo[1] = QString(tmpStr.mid(pos1, pos2 - pos1));
    }
    file.close();

    vInfo[2] = QSysInfo::productType();

    file.setFileName("/proc/sys/kernel/version");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: can't open sys/kernel/version";
    }
    res = file.readLine(buf, sizeof(buf));
    if (res > 0) {
        tmpStr = QString(buf);
        vInfo[3] = QString(tmpStr.mid(0, tmpStr.size() - 1));
    }
    return vInfo;
}
