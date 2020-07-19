#include "netusageinfo.h"

NetUsageInfo::NetUsageInfo(QObject* parent) : QObject(parent) {
    QString tmpStr;
    std::string tmp;
    char buf[1024];
    int res;
    int flag = 0;
    int heard = -1;

    file.setFileName("/proc/net/dev");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: open /proc/net/dev failed!";
        return;
    }

    for (int i = 0; i < 2; i++) res = file.readLine(buf, sizeof(buf));

    while (flag < 2) {
        res = file.readLine(buf, sizeof(buf));
        if (res <= 0) {
            qDebug() << "error: read /proc/net/dev failed!";
            break;
        }
        tmpStr = QString(buf);
        if ((heard = tmpStr.indexOf("eno1")) != -1 ||
            (heard = tmpStr.indexOf("wlo1")) != -1) {
            std::stringstream ss;
            ss << tmpStr.toStdString();
            ss >> tmp;
            tmp.pop_back();
            names.append(QString::fromStdString(tmp));
            receives.append(0);
            transmits.append(0);
            flag++;
        }
    }
    file.close();
}

QVector<double> NetUsageInfo::getTransmitData() { return transmits; }

QVector<double> NetUsageInfo::getReceiveData() { return receives; }

bool NetUsageInfo::refreshNetData() {
    QVector<qint64> receive1;
    QVector<qint64> transmit1;
    QVector<qint64> receive2;
    QVector<qint64> transmit2;

    sampling(receive1, transmit1);
    int time = 100;
    sleep(time);
    sampling(receive2, transmit2);

    for (int i = 0; i < receives.size(); i++) {
        receives.replace(
            i, 1.0 * (receive2.at(i) - receive1.at(i)) / (time * 1.0 / 1000));
        transmits.replace(
            i, 1.0 * (transmit2.at(i) - transmit1.at(i)) / (time * 1.0 / 1000));
    }
    return true;
}

bool NetUsageInfo::sampling(QVector<qint64>& receive,
                            QVector<qint64>& transmit) {
    QString tmpStr;
    char buf[1024];
    std::string tmp;
    int res;
    qint64 col;
    int flag = 0;
    int heard = -1;

    file.setFileName("/proc/net/dev");

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: open /proc/net/dev failed!";
        return false;
    }

    for (int i = 0; i < 2; i++) res = file.readLine(buf, sizeof(buf));

    while (flag < 2) {
        res = file.readLine(buf, sizeof(buf));
        if (res <= 0) {
            qDebug() << "error: read /proc/net/dev failed!";
            break;
        }
        tmpStr = QString(buf);
        if ((heard = tmpStr.indexOf("eno1")) != -1 ||
            (heard = tmpStr.indexOf("wlo1")) != -1) {
            std::stringstream ss;
            ss << tmpStr.toStdString();
            ss >> tmp;

            for (int i = 0; i < 9; i++) {
                ss >> col;
                if (i == 0)
                    receive.append(col);
                else if (i == 8)
                    transmit.append(col);
            }
            flag++;
        }
    }
    file.close();
    return true;
}

void NetUsageInfo::sleep(unsigned int msec) {
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents();
    }
}
