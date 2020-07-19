#include "cpuusageinfo.h"

CPUUsageInfo::CPUUsageInfo(QObject *parent) : QObject(parent) {
    for (int i = 0; i < 9; i++) cpuRate.append(0);
}

bool CPUUsageInfo::refreshCPURate() {
    QVector<qint64> idles1;
    QVector<qint64> totals1;
    QVector<qint64> idles2;
    QVector<qint64> totals2;

    sampling(idles1, totals1);
    sleep(70);
    sampling(idles2, totals2);
    if (idles1.at(0) == idles2.at(0)) return false;
    for (int i = 0; i < 9; i++)
        cpuRate.replace(i, 1 - 1.0 * (idles2.at(i) - idles1.at(i)) /
                                   (totals2.at(i) - totals1.at(i)));
    return true;
}

bool CPUUsageInfo::sampling(QVector<qint64> &idles, QVector<qint64> &totals) {
    int res;
    QString tmpStr;
    char buf[1024];
    std::string tmp;
    int t;
    int total;

    file.setFileName("/proc/stat");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: open /proc/stat failed!";
        return false;
    }

    for (int i = 0; i < 9; i++) {
        total = 0;
        res = file.readLine(buf, sizeof(buf));
        if (res <= 0) {
            qDebug() << "read /proc/stat failed!";
            return false;
        }
        tmpStr = QString(buf);

        std::stringstream ss;
        ss << tmpStr.toStdString();
        ss >> tmp;
        for (int i = 0; i < 7; i++) {
            ss >> t;
            total += t;
            if (i == 3) idles.append(t);
        }
        totals.append(total);
    }
    file.close();
    return true;
}

QVector<double> CPUUsageInfo::getCPURate() { return cpuRate; }

void CPUUsageInfo::sleep(unsigned int msec) {
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents();
    }
}
