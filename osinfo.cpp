#include "osinfo.h"

OSInfo::OSInfo(QObject *parent) : QObject(parent) {}

QVector<QString> OSInfo::getLoadAvg() {
    QVector<QString> osInfo(5, "\0");
    char buf[1024];
    QString tmpStr;
    int res;
    int flag = 0;

    file.setFileName("/proc/loadavg");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: can't open loadavg";
        return osInfo;
    }

    while (flag < 1) {
        res = file.readLine(buf, sizeof(buf));
        if (res <= 0) break;
        tmpStr = QString(buf);
        double loads[3];
        std::string tasks;
        std::string procedure;

        std::string tmp = tmpStr.toStdString();
        std::stringstream ss;

        ss << tmp;
        for (int i = 0; i < 3; i++) {
            ss >> loads[i];
            osInfo[i] = QString::number(loads[i]);
        }
        ss >> tasks;
        ss >> procedure;

        osInfo[3] = QString::fromStdString(tasks);
        osInfo[4] = QString::fromStdString(procedure);
        file.close();
        flag++;
    }
    return osInfo;
}

QVector<QString> OSInfo::getTime() {
    QVector<QString> timeInfo(2, "\0");
    char buf[1024];
    QString tmpStr;
    int res;
    int flag = 0;
    file.setFileName("/proc/uptime");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: can't open uptime";
        return timeInfo;
    }

    while (flag < 1) {
        res = file.readLine(buf, sizeof(buf));
        if (res <= 0) break;
        tmpStr = QString(buf);
        double times[2];

        std::string tmp = tmpStr.toStdString();
        std::stringstream ss;

        ss << tmp;
        for (int i = 0; i < 2; i++) {
            tmp.clear();
            ss >> times[i];
            timeInfo[i] =
                QString::number((int)times[i] / (3600 * 24)) + "天" +
                QString::number(((int)times[i] / 3600) % 24) + "时" +
                QString::number(((int)times[i] / 60) % 60) + "分" +
                QString::number((int)times[i] % 60 + times[i] - (int)times[i]) +
                "秒";
        }
        file.close();
        flag++;
    }
    return timeInfo;
}
