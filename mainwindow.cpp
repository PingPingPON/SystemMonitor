#include "mainwindow.h"

#include "cpuusageinfo.h"
#include "diskinfo.h"
#include "memusageinfo.h"
#include "netusageinfo.h"
#include "osinfo.h"
#include "systeminfo.h"
#include "cmake-build-debug/SystemMonitor_autogen/include/ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    connectMySQL();
    createDB();
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/icon"));
    this->setWindowTitle("系统监视器");

    cpuAxisX = new QValueAxis;
    cpuAxisY = new QValueAxis;
    memAxisX = new QValueAxis;
    memAxisY = new QValueAxis;
    netAxisX = new QValueAxis;
    netAxisY = new QValueAxis;

    timeCounter = 200;
    m_switch = this->startTimer(timeCounter);

    initial();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::initial() {
    setLineEdit();
    updateSysInfo();
    updateOSInfo();
    updateDiskInfo();
    setCPUInfo();
    setMemInfo();
    setNetInfo();
    updateSavedData();

    ui->tabWidget->setCurrentIndex(0);

    connect(ui->pb_confirm_fresh, SIGNAL(clicked(bool)), this,
            SLOT(setFreshTime()));
    connect(ui->pb_confirm_login, SIGNAL(clicked(bool)), this, SLOT(logIn()));
    connect(ui->pb_save, SIGNAL(clicked(bool)), this, SLOT(save2DB()));

    qDebug() << "Start Success.";
}

void MainWindow::connectMySQL() {
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setPort(3306);
    database.setDatabaseName("system_monitor");
    database.setUserName("root");
    database.setPassword("password");
    if (!database.open()) {
        qDebug() << database.lastError().text();
        return;
    }
}

void MainWindow::createDB() {
    if (database.isOpen()) {
        qDebug() << database.lastError().text();
        return;
    }
    database.exec("create database if not exists system_monitor");
    database.exec(
        "create table if not exists system_monitor.user(userName varchar(20) "
        "not null primary key, password varchar(18) null);");
    database.exec(
        "alter table system_monitor.user convert to characterset utf8;");
    database.exec(
        "create table if not exists system_monitor.deviceInfo( deviceName "
        "varchar(20) not null, diskSize varchar(20) not null, MAC varchar(17) "
        "not null, memSize varchar(20) not null, CPUModel varchar(50) not "
        "null, CPUCores varchar(2) not null, CPUFreq varchar(20) not null, "
        "CPUBuf varchar(20) not null);");
    database.exec(
        "alter table system_monitor.deviceInfo convert to characterset utf8;");
    database.exec(
        "create table if not exists system_monitor.OSInfo( kernelVersion "
        "varchar(30) not null, OSType varchar(30) not null, OSVersion "
        "varchar(50) not null,load1min varchar(10) not null,load5min "
        "varchar(10) not null,load15min varchar(10) not null,OSRunTime "
        "varchar(30) not null,OSFreeTime varchar(30) not null);");
    database.exec(
        "alter table system_monitor.OSInfo convert to characterset utf8;");
    database.exec(
        "create table if not exists system_monitor.CPUUsage( cpu double not "
        "null, cpu1 double not null, cpu2 double not null, cpu3 double not "
        "null, cpu4 double not null, cpu5 double not null, cpu6 double not "
        "null, cpu7 double not null, cpu8 double not null);");
    database.exec(
        "alter table system_monitor.CPUUsage convert to characterset utf8;");
    database.exec(
        "create table if not exists system_monitor.memUsage( memory double not "
        "null, swap double not null);");
    database.exec(
        "alter table system_monitor.memUsage convert to characterset utf8;");
    database.exec(
        "create table if not exists system_monitor.netSpeed( eno1_receive "
        "double not null, eno1_transmit double not null, wlo1_receive double "
        "not null, wlo1_transmit double not null);");
    database.exec(
        "alter table system_monitor.netSpeed convert to characterset utf8;");
    database.exec(
        "create table if not exists system_monitor.diskUsage( `/run` double "
        "not null, `/` double not null, `/tmp` double not null, `/home` double "
        "not null, `/boot` double not null, `/boot/efi` double not null, "
        "`/run/user/1000` double not null);");
    database.exec(
        "alter table system_monitor.diskUsage convert to characterset utf8;");

    if (database.lastError().isValid()) {
        qDebug() << database.lastError().text();
        return;
    }
}

void MainWindow::setLineEdit() {
    QIntValidator *intValidator = new QIntValidator;
    intValidator->setRange(100, 500);
    ui->le_fresh_time->setValidator(intValidator);
    ui->le_fresh_time->setPlaceholderText("输入刷新时间(100~500)(msec)");

    ui->le_user_name->setMaxLength(20);

    ui->le_password->setMaxLength(18);
    ui->le_password->setEchoMode(QLineEdit::Password);
}

void MainWindow::updateSysInfo() {
    SystemInfo sysInfo;

    QVector<QString> vcDevice = sysInfo.getDeviceInfo();
    QVector<QString> vcCPU = sysInfo.getCPUInfo();
    QVector<QString> vcVersion = sysInfo.getVersionInfo();

    ui->lb_device_name->setText(vcDevice.at(0));
    ui->lb_device_disk->setText(vcDevice.at(1) + " B");
    if (vcDevice.at(2) != '\0')
        ui->lb_device_IPv4->setText(vcDevice.at(2));
    else
        ui->lb_device_IPv4->setText("NULL");
    if (vcDevice.at(3) != "")
        ui->lb_device_IPv6->setText(vcDevice.at(3));
    else
        ui->lb_device_IPv6->setText("NULL");
    ui->lb_device_MAC->setText(vcDevice.at(4));
    ui->lb_device_mem->setText(vcDevice.at(5));
    ui->lb_CPU_model->setText(vcCPU.at(0));
    ui->lb_CPU_num->setText(vcCPU.at(1));
    ui->lb_CPU_freq->setText(vcCPU.at(2));
    ui->lb_CPU_buf->setText(vcCPU.at(3));
    ui->lb_V_kernel->setText(vcVersion.at(0));
    ui->lb_V_complier->setText(vcVersion.at(1));
    ui->lb_V_OS_type->setText(vcVersion.at(2));
    ui->lb_V_os_version->setText(vcVersion.at(3));
}

void MainWindow::updateOSInfo() {
    OSInfo osInfo;
    QVector<QString> vcLoadAvg = osInfo.getLoadAvg();
    QVector<QString> vcTime = osInfo.getTime();

    ui->lb_OS_load_1->setText(vcLoadAvg.at(0));
    ui->lb_OS_load_5->setText(vcLoadAvg.at(1));
    ui->lb_OS_load_15->setText(vcLoadAvg.at(2));

    ui->lb_OS_run_time->setText(vcTime.at(0));
    ui->lb_OS_free_time->setText(vcTime.at(1));
}

void MainWindow::setCPUInfo() {
    cpuAxisX->setRange(0, 60);
    cpuAxisX->setLabelFormat("%u");
    cpuAxisX->setGridLineVisible(true);
    cpuAxisX->setTickCount(10);
    cpuAxisX->setTitleText("时间节点");

    cpuAxisY->setRange(0, 1);
    cpuAxisY->setLabelFormat("%.1f");
    cpuAxisY->setGridLineVisible(true);
    cpuAxisY->setTickCount(6);
    cpuAxisY->setTitleText("CPU使用比率");

    ui->cv_CPU->chart()->addAxis(cpuAxisX, Qt::AlignBottom);
    ui->cv_CPU->chart()->addAxis(cpuAxisY, Qt::AlignLeft);

    for (int i = 0; i < 9; i++) {
        cpus[i] = new QSplineSeries();
        for (int j = 0; j <= 60; j++) cpus[i]->append(j, 0);
    }
    cpus[0]->setPen(QPen(Qt::black, Qt::SolidLine));
    cpus[0]->setName("cpu");

    cpus[1]->setPen(QPen(Qt::red, Qt::SolidLine));
    cpus[1]->setName("cpu1");

    cpus[2]->setPen(QPen(Qt::blue, Qt::SolidLine));
    cpus[2]->setName("cpu2");

    cpus[3]->setPen(QPen(Qt::green, Qt::SolidLine));
    cpus[3]->setName("cpu3");

    cpus[4]->setPen(QPen(Qt::yellow, Qt::SolidLine));
    cpus[4]->setName("cpu4");

    cpus[5]->setPen(QPen(Qt::cyan, Qt::SolidLine));
    cpus[5]->setName("cpu5");

    cpus[6]->setPen(QPen(Qt::magenta, Qt::SolidLine));
    cpus[6]->setName("cpu6");

    cpus[7]->setPen(QPen(Qt::darkGray, Qt::SolidLine));
    cpus[7]->setName("cpu7");

    cpus[8]->setPen(QPen(Qt::darkRed, Qt::SolidLine));
    cpus[8]->setName("cpu8");

    ui->cv_CPU->chart()->legend()->setVisible(true);
    ui->cv_CPU->chart()->legend()->setLayoutDirection(Qt::LeftToRight);
    ui->cv_CPU->chart()->legend()->setAlignment(Qt::AlignBottom);

    ui->cv_CPU->setRenderHint(QPainter::Antialiasing);

    for (int i = 0; i < 9; i++) {
        ui->cv_CPU->chart()->addSeries(cpus[i]);
        ui->cv_CPU->chart()->setAxisX(cpuAxisX, cpus[i]);
        ui->cv_CPU->chart()->setAxisY(cpuAxisY, cpus[i]);
    }
}

void MainWindow::updateCPUUsageInfo() {
    CPUUsageInfo cpuUsageInfo;
    cpuUsageInfo.refreshCPURate();

    for (int i = 0; i < 9; i++) {
        cpus[i]->remove(60);
        for (int j = 0; j < 60; j++)
            cpus[i]->replace(j, j + 1, cpus[i]->at(j).y());
        cpus[i]->insert(0, QPointF(0, cpuUsageInfo.getCPURate().at(i)));
    }
}

void MainWindow::setMemInfo() {
    memAxisX->setRange(0, 60);
    memAxisX->setLabelFormat("%u");
    memAxisX->setGridLineVisible(true);
    memAxisX->setTickCount(10);
    memAxisX->setTitleText("时间节点");

    memAxisY->setRange(0, 1);
    memAxisY->setLabelFormat("%.1f");
    memAxisY->setGridLineColor(true);
    memAxisY->setTickCount(6);
    memAxisY->setTitleText("内存占用比率");

    ui->cv_mem->chart()->addAxis(memAxisX, Qt::AlignBottom);
    ui->cv_mem->chart()->addAxis(memAxisY, Qt::AlignLeft);

    for (int i = 0; i < 2; i++) {
        mems[i] = new QSplineSeries;
        for (int j = 0; j <= 60; j++) mems[i]->append(j, 0);
    }
    mems[0]->setPen(QPen(Qt::red, Qt::SolidLine));
    mems[0]->setName("Memory");

    mems[1]->setPen(QPen(Qt::blue, Qt::SolidLine));
    mems[1]->setName("Swap");

    ui->cv_mem->chart()->legend()->setVisible(true);
    ui->cv_mem->chart()->legend()->setLayoutDirection(Qt::LeftToRight);
    ui->cv_mem->chart()->legend()->setAlignment(Qt::AlignBottom);

    ui->cv_mem->setRenderHint(QPainter::Antialiasing);
    for (int i = 0; i < 2; i++) {
        ui->cv_mem->chart()->addSeries(mems[i]);
        ui->cv_mem->chart()->setAxisX(memAxisX, mems[i]);
        ui->cv_mem->chart()->setAxisY(memAxisY, mems[i]);
    }
}

void MainWindow::updateMemUsageInfo() {
    memUsageInfo memusageinfo;
    memusageinfo.refreshMemRate();

    for (int i = 0; i < 2; i++) {
        mems[i]->remove(60);
        for (int j = 0; j < 60; j++)
            mems[i]->replace(j, j + 1, mems[i]->at(j).y());

        mems[i]->insert(0, QPointF(0, memusageinfo.getMemRate().at(i)));
    }
}

void MainWindow::setNetInfo() {
    netAxisX->setRange(0, 60);
    netAxisX->setLabelFormat("%u");
    netAxisX->setGridLineVisible(true);
    netAxisX->setTickCount(10);
    netAxisX->setTitleText("测试节点");

    netAxisY->setRange(0, 500);
    netAxisY->setLabelFormat("%.1f");
    netAxisY->setGridLineVisible(true);
    netAxisY->setTickCount(10);
    netAxisY->setTitleText("速率 byte/s");

    ui->cv_net->chart()->addAxis(netAxisX, Qt::AlignBottom);
    ui->cv_net->chart()->addAxis(netAxisY, Qt::AlignLeft);

    for (int i = 0; i < 4; i++) {
        nets[i] = new QSplineSeries;
        for (int j = 0; j <= 60; j++) nets[i]->append(j, 0);
        netMaxs[i] = 0;
        netMaxsCol[i] = 0;
    }

    netMax = 0;

    nets[0]->setPen(QPen(Qt::red, Qt::SolidLine));
    nets[0]->setName("eno1, receive");

    nets[1]->setPen(QPen(Qt::blue, Qt::SolidLine));
    nets[1]->setName("eno1, transmit");

    nets[2]->setPen(QPen(Qt::green, Qt::SolidLine));
    nets[2]->setName("wlo1, receive");

    nets[3]->setPen(QPen(Qt::yellow, Qt::SolidLine));
    nets[3]->setName("wlo1, transmit");

    for (int i = 0; i < 4; i++) {
        ui->cv_net->chart()->addSeries(nets[i]);
        ui->cv_net->chart()->setAxisX(netAxisX, nets[i]);
        ui->cv_net->chart()->setAxisY(netAxisY, nets[i]);
    }
}

void MainWindow::updateNetUsageInfo() {
    NetUsageInfo netusageinfo;
    netusageinfo.refreshNetData();

    for (int i = 0; i < 4; i++) {
        nets[i]->remove(60);
        for (int j = 0; j < 60; j++)
            nets[i]->replace(j, j + 1, nets[i]->at(j).y());
        netMaxsCol[i]++;
    }

    nets[0]->insert(0, QPointF(0, netusageinfo.getReceiveData().at(0)));
    nets[1]->insert(0, QPointF(0, netusageinfo.getTransmitData().at(0)));
    nets[2]->insert(0, QPointF(0, netusageinfo.getReceiveData().at(1)));
    nets[3]->insert(0, QPointF(0, netusageinfo.getTransmitData().at(1)));

    for (int i = 0; i < 4; i++) {
        if (nets[i]->at(0).y() > netMaxs[i]) {
            netMaxs[i] = nets[i]->at(0).y();
            netMaxsCol[i] = 0;
        } else if (netMaxsCol[i] == 61) {
            netMaxs[i] = 0;
            for (int j = 0; j <= 60; j++)
                if (nets[i]->at(j).y() > netMaxs[i]) {
                    netMaxs[i] = nets[i]->at(j).y();
                    netMaxsCol[i] = j;
                }
        }
    }
    netMax = 0;
    for (int i = 0; i < 4; i++)
        if (netMaxs[i] > netMax) netMax = netMaxs[i];

    netAxisY->setRange(0, netMax + 20);
}

void MainWindow::updateDiskInfo() {
    diskInfo diskinfo;
    QBarSet *qBarSet;
    QVector<QString> diskNames = diskinfo.getDiskName();
    QVector<qint64> diskBytesTotal = diskinfo.getDiskBytesTotal();
    QVector<qint64> diskBytesFree = diskinfo.getDiskBytesFree();
    QVector<qint64> diskBytesUsed = diskinfo.getDiskBytesUsed();
    QVector<double> diskBytesRate = diskinfo.getDiskBytesRate();

    diskSeries = new QBarSeries;

    diskAxisY = new QValueAxis;
    foreach (const QString &diskName, diskNames) {
        qBarSet = new QBarSet(diskName);
        disks.append(qBarSet);
        int col = diskNames.indexOf(diskName);
        qBarSet->append(diskBytesRate.at(col));
        qBarSet->setLabelColor(Qt::blue);

        diskSeries->append(qBarSet);
    }

    diskAxisY->setRange(0, 1);

    diskSeries->setVisible(true);
    diskSeries->setLabelsVisible(true);

    ui->cv_disk->chart()->setTheme(QChart::ChartThemeLight);
    ui->cv_disk->chart()->setDropShadowEnabled(true);
    ui->cv_disk->chart()->addSeries(diskSeries);
    ui->cv_disk->chart()->createDefaultAxes();

    ui->cv_disk->chart()->setAxisY(diskAxisY, diskSeries);

    ui->cv_disk->chart()->legend()->setVisible(true);
    ui->cv_disk->chart()->legend()->setAlignment(Qt::AlignBottom);
    ui->cv_disk->chart()->legend()->setAutoFillBackground(true);

    ui->cv_disk->chart()->setAnimationOptions(QChart::SeriesAnimations);
    ui->cv_disk->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::updateSavedData(){
    if(!database.isOpen())
        return;
    QSqlQueryModel *model0 = new QSqlQueryModel(ui->tv_saved_device_data);
    QSqlQueryModel *model1 = new QSqlQueryModel(ui->tv_saved_OS_data);
    QSqlQueryModel *model2 = new QSqlQueryModel(ui->tv_saved_CPU_data);
    QSqlQueryModel *model3 = new QSqlQueryModel(ui->tv_saved_mem_data);
    QSqlQueryModel *model4 = new QSqlQueryModel(ui->tv_saved_net_data);
    QSqlQueryModel *model5 = new QSqlQueryModel(ui->tv_saved_disk_data);

    model0->setQuery(QString("select * from deviceInfo;"));
    model0->setHeaderData(0, Qt::Horizontal, tr("设备名称"));
    model0->setHeaderData(1, Qt::Horizontal, tr("磁盘总容量"));
    model0->setHeaderData(2, Qt::Horizontal, tr("MAC地址"));
    model0->setHeaderData(3, Qt::Horizontal, tr("内存总量"));
    model0->setHeaderData(4, Qt::Horizontal, tr("CPU型号"));
    model0->setHeaderData(5, Qt::Horizontal, tr("CPU核数"));
    model0->setHeaderData(6, Qt::Horizontal, tr("CPU频率"));
    model0->setHeaderData(7, Qt::Horizontal, tr("缓存大小"));
    ui->tv_saved_device_data->setModel(model0);

    model1->setQuery(QString("select * from OSInfo;"));
    model1->setHeaderData(0, Qt::Horizontal, tr("内核版本"));
    model1->setHeaderData(1, Qt::Horizontal, tr("操作系统类型"));
    model1->setHeaderData(2, Qt::Horizontal, tr("操作系统版本"));
    model1->setHeaderData(3, Qt::Horizontal, tr("1分钟平均负载"));
    model1->setHeaderData(4, Qt::Horizontal, tr("5分钟平均负载"));
    model1->setHeaderData(5, Qt::Horizontal, tr("15分钟平均负载"));
    model1->setHeaderData(6, Qt::Horizontal, tr("运行时间"));
    model1->setHeaderData(7, Qt::Horizontal, tr("空闲时间"));
    ui->tv_saved_OS_data->setModel(model1);

    model2->setQuery(QString("select * from CPUUsage;"));
    model2->setHeaderData(0, Qt::Horizontal, tr("cpu"));
    model2->setHeaderData(1, Qt::Horizontal, tr("cpu1"));
    model2->setHeaderData(2, Qt::Horizontal, tr("cpu2"));
    model2->setHeaderData(3, Qt::Horizontal, tr("cpu3"));
    model2->setHeaderData(4, Qt::Horizontal, tr("cpu4"));
    model2->setHeaderData(5, Qt::Horizontal, tr("cpu5"));
    model2->setHeaderData(6, Qt::Horizontal, tr("cpu6"));
    model2->setHeaderData(7, Qt::Horizontal, tr("cpu7"));
    model2->setHeaderData(8, Qt::Horizontal, tr("cpu8"));
    ui->tv_saved_CPU_data->setModel(model2);

    model3->setQuery(QString("select * from memUsage;"));
    model3->setHeaderData(0, Qt::Horizontal, tr("memory"));
    model3->setHeaderData(1, Qt::Horizontal, tr("swap"));
    ui->tv_saved_mem_data->setModel(model3);

    model4->setQuery(QString("select * from netSpeed;"));
    model4->setHeaderData(0, Qt::Horizontal, tr("eno1_receive"));
    model4->setHeaderData(1, Qt::Horizontal, tr("eno1_transmit"));
    model4->setHeaderData(2, Qt::Horizontal, tr("wlo1_receive"));
    model4->setHeaderData(3, Qt::Horizontal, tr("wlo1_transmit"));
    ui->tv_saved_net_data->setModel(model4);

    model5->setQuery(QString("select * from diskUsage;"));
    model5->setHeaderData(0, Qt::Horizontal, tr("/run"));
    model5->setHeaderData(1, Qt::Horizontal, tr("/"));
    model5->setHeaderData(2, Qt::Horizontal, tr("/tmp"));
    model5->setHeaderData(3, Qt::Horizontal, tr("/home"));
    model5->setHeaderData(4, Qt::Horizontal, tr("/boot"));
    model5->setHeaderData(5, Qt::Horizontal, tr("/boot/efi"));
    model5->setHeaderData(6, Qt::Horizontal, tr("/run/user/1000"));
    ui->tv_saved_disk_data->setModel(model5);
}

void MainWindow::logIn() {
    QSqlQuery query;
    QString UName = ui->le_user_name->text();
    QString Pword = ui->le_password->text();

    QString s = QString(
                    "select * from system_monitor.user where userName='%1' and "
                    "password='%2'")
                    .arg(UName)
                    .arg(Pword);
    query.exec(s);

    if (query.first()) {
        QMessageBox::information(NULL, "登录成功", "登录成功",
                                 QMessageBox::Yes);
        login = true;
        ui->pb_confirm_login->setEnabled(false);
    } else
        QMessageBox::warning(NULL, "Error", "登录失败", "重试");
}

void MainWindow::setFreshTime() {
    if(ui->le_fresh_time->text().isEmpty()){
        QMessageBox::warning(NULL, "Error", "请勿输入空值", "重试");
        return;
    }
    if(ui->le_fresh_time->text().toInt()<100||ui->le_fresh_time->text().toInt()>500){
        QMessageBox::warning(NULL, "Error", "输入范围为100～500", "重试");

        ui->le_fresh_time->setText("");
        return;
    }
    timeCounter = ui->le_fresh_time->text().toInt();
    m_switch = this->startTimer(timeCounter);
    qDebug()<<timeCounter;
    QMessageBox::information(NULL, "修改成功", "修改成功",
                             QMessageBox::Yes);
    ui->le_fresh_time->setText(QString::number(timeCounter));
}

void MainWindow::save2DB() {
    if (!login) {
        QMessageBox::warning(NULL, "Error", "请先登录", "登录");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    QSqlQuery query;
    QString s;
    s = QString(
            "insert into deviceInfo values ('%1', '%2', '%3', '%4', '%5', "
            "'%6', '%7', '%8');")
            .arg(ui->lb_device_name->text())
            .arg(ui->lb_device_disk->text())
            .arg(ui->lb_device_MAC->text())
            .arg(ui->lb_device_mem->text())
            .arg(ui->lb_CPU_model->text())
            .arg(ui->lb_CPU_num->text())
            .arg(ui->lb_CPU_freq->text())
            .arg(ui->lb_CPU_buf->text());
    qDebug() << s;
    query.exec(s);

    s = QString(
            "insert into OSInfo values ('%1', '%2', '%3', '%4', '%5', '%6', "
            "'%7', '%8');")
            .arg(ui->lb_V_kernel->text())
            .arg(ui->lb_V_OS_type->text())
            .arg(ui->lb_V_os_version->text())
            .arg(ui->lb_OS_load_1->text())
            .arg(ui->lb_OS_load_5->text())
            .arg(ui->lb_OS_load_15->text())
            .arg(ui->lb_OS_run_time->text())
            .arg(ui->lb_OS_free_time->text());
    qDebug() << s;
    query.exec(s);

    CPUUsageInfo cpuUsageInfo;
    cpuUsageInfo.refreshCPURate();

    s = QString(
            "insert into CPUUsage values (%1, %2, %3, %4, %5, %6, %7, %8, %9);")
            .arg(cpuUsageInfo.getCPURate().at(0))
            .arg(cpuUsageInfo.getCPURate().at(1))
            .arg(cpuUsageInfo.getCPURate().at(2))
            .arg(cpuUsageInfo.getCPURate().at(3))
            .arg(cpuUsageInfo.getCPURate().at(4))
            .arg(cpuUsageInfo.getCPURate().at(5))
            .arg(cpuUsageInfo.getCPURate().at(6))
            .arg(cpuUsageInfo.getCPURate().at(7))
            .arg(cpuUsageInfo.getCPURate().at(8));
    qDebug() << s;
    query.exec(s);

    memUsageInfo memusageinfo;
    memusageinfo.refreshMemRate();

    s = QString("insert into memUsage values (%1, %2);")
            .arg(memusageinfo.getMemRate().at(0))
            .arg(memusageinfo.getMemRate().at(1));
    qDebug() << s;
    query.exec(s);

    NetUsageInfo netusageinfo;
    netusageinfo.refreshNetData();

    s = QString("insert into netSpeed values (%1, %2, %3, %4);")
            .arg(netusageinfo.getReceiveData().at(0))
            .arg(netusageinfo.getTransmitData().at(0))
            .arg(netusageinfo.getReceiveData().at(1))
            .arg(netusageinfo.getTransmitData().at(1));
    qDebug() << s;
    query.exec(s);

    diskInfo diskinfo;
    QVector<qint64> diskBytesTotal = diskinfo.getDiskBytesTotal();
    QVector<qint64> diskBytesFree = diskinfo.getDiskBytesFree();
    QVector<qint64> diskBytesUsed = diskinfo.getDiskBytesUsed();

    s = QString("insert into diskUsage values (%1, %2, %3, %4, %5, %6, %7);")
            .arg(1.0 * diskinfo.getDiskBytesUsed().at(0) /
                 diskinfo.getDiskBytesTotal().at(0))
            .arg(1.0 * diskinfo.getDiskBytesUsed().at(1) /
                 diskinfo.getDiskBytesTotal().at(1))
            .arg(1.0 * diskinfo.getDiskBytesUsed().at(2) /
                 diskinfo.getDiskBytesTotal().at(2))
            .arg(1.0 * diskinfo.getDiskBytesUsed().at(3) /
                 diskinfo.getDiskBytesTotal().at(3))
            .arg(1.0 * diskinfo.getDiskBytesUsed().at(4) /
                 diskinfo.getDiskBytesTotal().at(4))
            .arg(1.0 * diskinfo.getDiskBytesUsed().at(5) /
                 diskinfo.getDiskBytesTotal().at(5))
            .arg(1.0 * diskinfo.getDiskBytesUsed().at(6) /
                 diskinfo.getDiskBytesTotal().at(6));
    qDebug() << s;
    query.exec(s);

    QMessageBox::information(NULL, "保存成功", "保存成功", QMessageBox::Yes);
    updateSavedData();
}

void MainWindow::timerEvent(QTimerEvent *event) {
    if (event->timerId() == this->m_switch) {
        updateOSInfo();
        updateCPUUsageInfo();
        updateMemUsageInfo();
        updateNetUsageInfo();
    }
}
