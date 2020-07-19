#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QtCharts>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

   public slots:
    void setFreshTime();
    void logIn();
    void save2DB();

   protected:
    void timerEvent(QTimerEvent *event);

   private:
    Ui::MainWindow *ui;
    int timeCounter;
    bool login = false;

    void connectMySQL();
    void createDB();

    QSqlDatabase database;

    QSplineSeries *cpus[9]{};
    QSplineSeries *mems[2]{};
    QSplineSeries *nets[4]{};
    QVector<QBarSet *> disks;
    QBarSeries *diskSeries{};

    QValueAxis *cpuAxisX;
    QValueAxis *cpuAxisY;
    QValueAxis *memAxisX;
    QValueAxis *memAxisY;
    QValueAxis *netAxisX;
    QValueAxis *netAxisY;
    //    QBarCategoryAxis *diskAxisX;
    QValueAxis *diskAxisY{};

    void initial();

    void updateSysInfo();

    void updateOSInfo();

    void setCPUInfo();

    void updateCPUUsageInfo();

    void setMemInfo();

    void updateMemUsageInfo();

    void setNetInfo();

    void updateNetUsageInfo();

    void updateDiskInfo();

    void updateSavedData();

    void setLineEdit();

    int netMaxs[4]{}, netMaxsCol[4]{}, netMax{};

    int m_switch;

    //    bool boundTable(QString item);
};

#endif  // MAINWINDOW_H
