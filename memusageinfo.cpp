#include "memusageinfo.h"

memUsageInfo::memUsageInfo(QObject *parent) : QObject(parent) {
    memRate = 0;
    swapRate = 0;
    memAll = 0;
    swapAll = 0;
}

QVector<double> memUsageInfo::getMemRate() {
    QVector<double> tmp;
    tmp.append(memRate);
    tmp.append(swapRate);
    return tmp;
}

QVector<int> memUsageInfo::getMemAll() {
    QVector<int> tmp;
    tmp.append(memAll);
    tmp.append(swapAll);
    return tmp;
}

bool memUsageInfo::refreshMemRate() {
    QString tmpStr;
    std::string tmp;
    char buf[1024];
    int res;
    int flag = 0;
    int heard = -1;

    file.setFileName("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: open /proc/meminfo failed!";
        return false;
    }

    while (flag < 4) {
        res = file.readLine(buf, sizeof(buf));
        if (res <= 0) {
            qDebug() << "error: read /proc/meminfo failed!";
            break;
        }
        tmpStr = QString(buf);

        if ((heard = tmpStr.indexOf("MemTotal")) != -1) {
            std::stringstream ss;
            ss << tmpStr.toStdString();
            ss >> tmp;
            ss >> memAll;
            flag++;
        } else if ((heard = tmpStr.indexOf("MemAvailable")) != -1) {
            std::stringstream ss;
            ss << tmpStr.toStdString();
            ss >> tmp;
            ss >> memAvailable;
            flag++;
        } else if ((heard = tmpStr.indexOf("SwapTotal")) != -1) {
            std::stringstream ss;
            ss << tmpStr.toStdString();
            ss >> tmp;
            ss >> swapAll;
            flag++;
        } else if ((heard = tmpStr.indexOf("SwapFree")) != -1) {
            std::stringstream ss;
            ss << tmpStr.toStdString();
            ss >> tmp;
            ss >> swapAvailable;
            flag++;
        }
    }
    file.close();

    int memUsed = memAll - memAvailable;
    int swapUsed = swapAll - swapAvailable;

    memRate = memUsed * 1.0 / memAll;
    swapRate = swapUsed * 1.0 / swapAll;
    return true;
}
