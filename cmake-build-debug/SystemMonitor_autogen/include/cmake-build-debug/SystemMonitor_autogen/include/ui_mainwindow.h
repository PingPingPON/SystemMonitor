/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayoutTab;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QLabel *lb_user_name;
    QLabel *lb_password;
    QLineEdit *le_user_name;
    QLineEdit *le_password;
    QPushButton *pb_confirm_login;
    QWidget *tab_sys;
    QVBoxLayout *verticalLayoutSystemInfo;
    QGroupBox *gb_device_info;
    QVBoxLayout *verticalLayoutDeviceInfo;
    QHBoxLayout *hl_device_name;
    QLabel *labelDeviceName;
    QLabel *lb_device_name;
    QHBoxLayout *hl_device_disk;
    QLabel *labelDiskSize;
    QLabel *lb_device_disk;
    QHBoxLayout *hl_device_IPv4;
    QLabel *labelIPv4;
    QLabel *lb_device_IPv4;
    QHBoxLayout *hl_device_IPv6;
    QLabel *labelIPv6;
    QLabel *lb_device_IPv6;
    QHBoxLayout *hl_device_MAC;
    QLabel *labelMAC;
    QLabel *lb_device_MAC;
    QHBoxLayout *hl_device_mem;
    QLabel *labelMem;
    QLabel *lb_device_mem;
    QGroupBox *gb_CPU_info;
    QVBoxLayout *verticalLayoutCPUInfo;
    QHBoxLayout *hl_CPU_model;
    QLabel *labelCPUModel;
    QLabel *lb_CPU_model;
    QHBoxLayout *hl_CPU_num;
    QLabel *labelCPUCores;
    QLabel *lb_CPU_num;
    QHBoxLayout *hl_CPU_freq;
    QLabel *labelCPUFreq;
    QLabel *lb_CPU_freq;
    QLabel *labelCPUMHZ;
    QHBoxLayout *h1_CPU_buf;
    QLabel *labelCPUBuf;
    QLabel *lb_CPU_buf;
    QGroupBox *gb_V_info;
    QVBoxLayout *verticalLayoutVersionInfo;
    QHBoxLayout *hl_V_kernel;
    QLabel *labelKernelVersion;
    QLabel *lb_V_kernel;
    QHBoxLayout *hl_V_complier;
    QLabel *labelComplier;
    QLabel *lb_V_complier;
    QHBoxLayout *hl_V_os_type;
    QLabel *labelOSType;
    QLabel *lb_V_OS_type;
    QHBoxLayout *hl_V_OS_version;
    QLabel *labelOSVersion;
    QLabel *lb_V_os_version;
    QWidget *tab_OS;
    QVBoxLayout *verticalLayoutSystemInfo1;
    QGroupBox *gb_OS_load;
    QVBoxLayout *verticalLayoutOSLoad;
    QHBoxLayout *hl_OS_load_1;
    QLabel *labelOSLoad1;
    QLabel *lb_OS_load_1;
    QHBoxLayout *hl_OS_load_5;
    QLabel *labelOSLoad5;
    QLabel *lb_OS_load_5;
    QHBoxLayout *hl_OS_load_15;
    QLabel *labelOSLoad15;
    QLabel *lb_OS_load_15;
    QGroupBox *gb_OS_time;
    QVBoxLayout *verticalLayoutOSTime;
    QHBoxLayout *hl_OS_run_time;
    QLabel *labelOSRunTime;
    QLabel *lb_OS_run_time;
    QHBoxLayout *hl_OS_free_time;
    QLabel *labelOSFreeTime;
    QLabel *lb_OS_free_time;
    QWidget *tab_CPU_data;
    QVBoxLayout *verticalLayoutCPUData;
    QChartView *cv_CPU;
    QWidget *tab_mem_data;
    QVBoxLayout *verticalLayoutMemData;
    QChartView *cv_mem;
    QWidget *tab_net_data;
    QVBoxLayout *verticalLayoutNetData;
    QChartView *cv_net;
    QWidget *tab_disk_data;
    QVBoxLayout *verticalLayoutNetData1;
    QChartView *cv_disk;
    QWidget *tab_saved_device_data;
    QVBoxLayout *verticalLayoutSavedDeviceData;
    QTableView *tv_saved_device_data;
    QWidget *tab_saved_OS_data;
    QVBoxLayout *verticalLayoutSavedOSData;
    QTableView *tv_saved_OS_data;
    QWidget *tab_saved_CPU_data;
    QVBoxLayout *verticalLayoutSavedCPUData;
    QTableView *tv_saved_CPU_data;
    QWidget *tab_saved_mem_data;
    QVBoxLayout *verticalLayoutSavedMemData;
    QTableView *tv_saved_mem_data;
    QWidget *tab_saved_net_data;
    QVBoxLayout *verticalLayoutSavedNetData;
    QTableView *tv_saved_net_data;
    QWidget *tab_saved_disk_data;
    QVBoxLayout *verticalLayoutSavedDiskData;
    QTableView *tv_saved_disk_data;
    QWidget *tab_setting;
    QPushButton *pb_save;
    QLineEdit *le_fresh_time;
    QPushButton *pb_confirm_fresh;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1350, 633);
        MainWindow->setMinimumSize(QSize(1350, 633));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutTab = new QHBoxLayout(centralwidget);
        horizontalLayoutTab->setObjectName(QString::fromUtf8("horizontalLayoutTab"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(420, 550));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        lb_user_name = new QLabel(tab_2);
        lb_user_name->setObjectName(QString::fromUtf8("lb_user_name"));
        lb_user_name->setGeometry(QRect(250, 120, 61, 17));
        lb_password = new QLabel(tab_2);
        lb_password->setObjectName(QString::fromUtf8("lb_password"));
        lb_password->setGeometry(QRect(250, 180, 61, 17));
        le_user_name = new QLineEdit(tab_2);
        le_user_name->setObjectName(QString::fromUtf8("le_user_name"));
        le_user_name->setGeometry(QRect(340, 120, 271, 25));
        le_password = new QLineEdit(tab_2);
        le_password->setObjectName(QString::fromUtf8("le_password"));
        le_password->setGeometry(QRect(340, 180, 271, 25));
        pb_confirm_login = new QPushButton(tab_2);
        pb_confirm_login->setObjectName(QString::fromUtf8("pb_confirm_login"));
        pb_confirm_login->setGeometry(QRect(520, 270, 80, 25));
        tabWidget->addTab(tab_2, QString());
        tab_sys = new QWidget();
        tab_sys->setObjectName(QString::fromUtf8("tab_sys"));
        verticalLayoutSystemInfo = new QVBoxLayout(tab_sys);
        verticalLayoutSystemInfo->setObjectName(QString::fromUtf8("verticalLayoutSystemInfo"));
        gb_device_info = new QGroupBox(tab_sys);
        gb_device_info->setObjectName(QString::fromUtf8("gb_device_info"));
        sizePolicy.setHeightForWidth(gb_device_info->sizePolicy().hasHeightForWidth());
        gb_device_info->setSizePolicy(sizePolicy);
        gb_device_info->setMinimumSize(QSize(420, 240));
        verticalLayoutDeviceInfo = new QVBoxLayout(gb_device_info);
        verticalLayoutDeviceInfo->setObjectName(QString::fromUtf8("verticalLayoutDeviceInfo"));
        hl_device_name = new QHBoxLayout();
        hl_device_name->setObjectName(QString::fromUtf8("hl_device_name"));
        labelDeviceName = new QLabel(gb_device_info);
        labelDeviceName->setObjectName(QString::fromUtf8("labelDeviceName"));
        sizePolicy.setHeightForWidth(labelDeviceName->sizePolicy().hasHeightForWidth());
        labelDeviceName->setSizePolicy(sizePolicy);

        hl_device_name->addWidget(labelDeviceName);

        lb_device_name = new QLabel(gb_device_info);
        lb_device_name->setObjectName(QString::fromUtf8("lb_device_name"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lb_device_name->sizePolicy().hasHeightForWidth());
        lb_device_name->setSizePolicy(sizePolicy1);

        hl_device_name->addWidget(lb_device_name);


        verticalLayoutDeviceInfo->addLayout(hl_device_name);

        hl_device_disk = new QHBoxLayout();
        hl_device_disk->setObjectName(QString::fromUtf8("hl_device_disk"));
        labelDiskSize = new QLabel(gb_device_info);
        labelDiskSize->setObjectName(QString::fromUtf8("labelDiskSize"));
        sizePolicy.setHeightForWidth(labelDiskSize->sizePolicy().hasHeightForWidth());
        labelDiskSize->setSizePolicy(sizePolicy);

        hl_device_disk->addWidget(labelDiskSize);

        lb_device_disk = new QLabel(gb_device_info);
        lb_device_disk->setObjectName(QString::fromUtf8("lb_device_disk"));
        sizePolicy1.setHeightForWidth(lb_device_disk->sizePolicy().hasHeightForWidth());
        lb_device_disk->setSizePolicy(sizePolicy1);

        hl_device_disk->addWidget(lb_device_disk);


        verticalLayoutDeviceInfo->addLayout(hl_device_disk);

        hl_device_IPv4 = new QHBoxLayout();
        hl_device_IPv4->setObjectName(QString::fromUtf8("hl_device_IPv4"));
        labelIPv4 = new QLabel(gb_device_info);
        labelIPv4->setObjectName(QString::fromUtf8("labelIPv4"));
        sizePolicy.setHeightForWidth(labelIPv4->sizePolicy().hasHeightForWidth());
        labelIPv4->setSizePolicy(sizePolicy);

        hl_device_IPv4->addWidget(labelIPv4);

        lb_device_IPv4 = new QLabel(gb_device_info);
        lb_device_IPv4->setObjectName(QString::fromUtf8("lb_device_IPv4"));
        sizePolicy1.setHeightForWidth(lb_device_IPv4->sizePolicy().hasHeightForWidth());
        lb_device_IPv4->setSizePolicy(sizePolicy1);

        hl_device_IPv4->addWidget(lb_device_IPv4);


        verticalLayoutDeviceInfo->addLayout(hl_device_IPv4);

        hl_device_IPv6 = new QHBoxLayout();
        hl_device_IPv6->setObjectName(QString::fromUtf8("hl_device_IPv6"));
        labelIPv6 = new QLabel(gb_device_info);
        labelIPv6->setObjectName(QString::fromUtf8("labelIPv6"));
        sizePolicy.setHeightForWidth(labelIPv6->sizePolicy().hasHeightForWidth());
        labelIPv6->setSizePolicy(sizePolicy);

        hl_device_IPv6->addWidget(labelIPv6);

        lb_device_IPv6 = new QLabel(gb_device_info);
        lb_device_IPv6->setObjectName(QString::fromUtf8("lb_device_IPv6"));
        sizePolicy1.setHeightForWidth(lb_device_IPv6->sizePolicy().hasHeightForWidth());
        lb_device_IPv6->setSizePolicy(sizePolicy1);

        hl_device_IPv6->addWidget(lb_device_IPv6);


        verticalLayoutDeviceInfo->addLayout(hl_device_IPv6);

        hl_device_MAC = new QHBoxLayout();
        hl_device_MAC->setObjectName(QString::fromUtf8("hl_device_MAC"));
        labelMAC = new QLabel(gb_device_info);
        labelMAC->setObjectName(QString::fromUtf8("labelMAC"));
        sizePolicy.setHeightForWidth(labelMAC->sizePolicy().hasHeightForWidth());
        labelMAC->setSizePolicy(sizePolicy);

        hl_device_MAC->addWidget(labelMAC);

        lb_device_MAC = new QLabel(gb_device_info);
        lb_device_MAC->setObjectName(QString::fromUtf8("lb_device_MAC"));
        sizePolicy1.setHeightForWidth(lb_device_MAC->sizePolicy().hasHeightForWidth());
        lb_device_MAC->setSizePolicy(sizePolicy1);

        hl_device_MAC->addWidget(lb_device_MAC);


        verticalLayoutDeviceInfo->addLayout(hl_device_MAC);

        hl_device_mem = new QHBoxLayout();
        hl_device_mem->setObjectName(QString::fromUtf8("hl_device_mem"));
        labelMem = new QLabel(gb_device_info);
        labelMem->setObjectName(QString::fromUtf8("labelMem"));
        sizePolicy.setHeightForWidth(labelMem->sizePolicy().hasHeightForWidth());
        labelMem->setSizePolicy(sizePolicy);

        hl_device_mem->addWidget(labelMem);

        lb_device_mem = new QLabel(gb_device_info);
        lb_device_mem->setObjectName(QString::fromUtf8("lb_device_mem"));
        sizePolicy1.setHeightForWidth(lb_device_mem->sizePolicy().hasHeightForWidth());
        lb_device_mem->setSizePolicy(sizePolicy1);

        hl_device_mem->addWidget(lb_device_mem);


        verticalLayoutDeviceInfo->addLayout(hl_device_mem);


        verticalLayoutSystemInfo->addWidget(gb_device_info);

        gb_CPU_info = new QGroupBox(tab_sys);
        gb_CPU_info->setObjectName(QString::fromUtf8("gb_CPU_info"));
        sizePolicy.setHeightForWidth(gb_CPU_info->sizePolicy().hasHeightForWidth());
        gb_CPU_info->setSizePolicy(sizePolicy);
        gb_CPU_info->setMinimumSize(QSize(420, 160));
        verticalLayoutCPUInfo = new QVBoxLayout(gb_CPU_info);
        verticalLayoutCPUInfo->setObjectName(QString::fromUtf8("verticalLayoutCPUInfo"));
        hl_CPU_model = new QHBoxLayout();
        hl_CPU_model->setObjectName(QString::fromUtf8("hl_CPU_model"));
        labelCPUModel = new QLabel(gb_CPU_info);
        labelCPUModel->setObjectName(QString::fromUtf8("labelCPUModel"));
        sizePolicy.setHeightForWidth(labelCPUModel->sizePolicy().hasHeightForWidth());
        labelCPUModel->setSizePolicy(sizePolicy);

        hl_CPU_model->addWidget(labelCPUModel);

        lb_CPU_model = new QLabel(gb_CPU_info);
        lb_CPU_model->setObjectName(QString::fromUtf8("lb_CPU_model"));
        sizePolicy1.setHeightForWidth(lb_CPU_model->sizePolicy().hasHeightForWidth());
        lb_CPU_model->setSizePolicy(sizePolicy1);

        hl_CPU_model->addWidget(lb_CPU_model);


        verticalLayoutCPUInfo->addLayout(hl_CPU_model);

        hl_CPU_num = new QHBoxLayout();
        hl_CPU_num->setObjectName(QString::fromUtf8("hl_CPU_num"));
        labelCPUCores = new QLabel(gb_CPU_info);
        labelCPUCores->setObjectName(QString::fromUtf8("labelCPUCores"));
        sizePolicy.setHeightForWidth(labelCPUCores->sizePolicy().hasHeightForWidth());
        labelCPUCores->setSizePolicy(sizePolicy);

        hl_CPU_num->addWidget(labelCPUCores);

        lb_CPU_num = new QLabel(gb_CPU_info);
        lb_CPU_num->setObjectName(QString::fromUtf8("lb_CPU_num"));
        sizePolicy1.setHeightForWidth(lb_CPU_num->sizePolicy().hasHeightForWidth());
        lb_CPU_num->setSizePolicy(sizePolicy1);

        hl_CPU_num->addWidget(lb_CPU_num);


        verticalLayoutCPUInfo->addLayout(hl_CPU_num);

        hl_CPU_freq = new QHBoxLayout();
        hl_CPU_freq->setObjectName(QString::fromUtf8("hl_CPU_freq"));
        hl_CPU_freq->setSizeConstraint(QLayout::SetDefaultConstraint);
        hl_CPU_freq->setContentsMargins(-1, -1, 0, -1);
        labelCPUFreq = new QLabel(gb_CPU_info);
        labelCPUFreq->setObjectName(QString::fromUtf8("labelCPUFreq"));
        sizePolicy.setHeightForWidth(labelCPUFreq->sizePolicy().hasHeightForWidth());
        labelCPUFreq->setSizePolicy(sizePolicy);

        hl_CPU_freq->addWidget(labelCPUFreq);

        lb_CPU_freq = new QLabel(gb_CPU_info);
        lb_CPU_freq->setObjectName(QString::fromUtf8("lb_CPU_freq"));
        sizePolicy.setHeightForWidth(lb_CPU_freq->sizePolicy().hasHeightForWidth());
        lb_CPU_freq->setSizePolicy(sizePolicy);

        hl_CPU_freq->addWidget(lb_CPU_freq);

        labelCPUMHZ = new QLabel(gb_CPU_info);
        labelCPUMHZ->setObjectName(QString::fromUtf8("labelCPUMHZ"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelCPUMHZ->sizePolicy().hasHeightForWidth());
        labelCPUMHZ->setSizePolicy(sizePolicy2);

        hl_CPU_freq->addWidget(labelCPUMHZ);


        verticalLayoutCPUInfo->addLayout(hl_CPU_freq);

        h1_CPU_buf = new QHBoxLayout();
        h1_CPU_buf->setObjectName(QString::fromUtf8("h1_CPU_buf"));
        h1_CPU_buf->setSizeConstraint(QLayout::SetDefaultConstraint);
        h1_CPU_buf->setContentsMargins(-1, -1, 0, -1);
        labelCPUBuf = new QLabel(gb_CPU_info);
        labelCPUBuf->setObjectName(QString::fromUtf8("labelCPUBuf"));
        sizePolicy.setHeightForWidth(labelCPUBuf->sizePolicy().hasHeightForWidth());
        labelCPUBuf->setSizePolicy(sizePolicy);

        h1_CPU_buf->addWidget(labelCPUBuf);

        lb_CPU_buf = new QLabel(gb_CPU_info);
        lb_CPU_buf->setObjectName(QString::fromUtf8("lb_CPU_buf"));
        sizePolicy1.setHeightForWidth(lb_CPU_buf->sizePolicy().hasHeightForWidth());
        lb_CPU_buf->setSizePolicy(sizePolicy1);

        h1_CPU_buf->addWidget(lb_CPU_buf);


        verticalLayoutCPUInfo->addLayout(h1_CPU_buf);


        verticalLayoutSystemInfo->addWidget(gb_CPU_info);

        gb_V_info = new QGroupBox(tab_sys);
        gb_V_info->setObjectName(QString::fromUtf8("gb_V_info"));
        sizePolicy.setHeightForWidth(gb_V_info->sizePolicy().hasHeightForWidth());
        gb_V_info->setSizePolicy(sizePolicy);
        gb_V_info->setMinimumSize(QSize(420, 120));
        verticalLayoutVersionInfo = new QVBoxLayout(gb_V_info);
        verticalLayoutVersionInfo->setObjectName(QString::fromUtf8("verticalLayoutVersionInfo"));
        hl_V_kernel = new QHBoxLayout();
        hl_V_kernel->setObjectName(QString::fromUtf8("hl_V_kernel"));
        hl_V_kernel->setSizeConstraint(QLayout::SetDefaultConstraint);
        hl_V_kernel->setContentsMargins(-1, -1, 0, -1);
        labelKernelVersion = new QLabel(gb_V_info);
        labelKernelVersion->setObjectName(QString::fromUtf8("labelKernelVersion"));
        sizePolicy.setHeightForWidth(labelKernelVersion->sizePolicy().hasHeightForWidth());
        labelKernelVersion->setSizePolicy(sizePolicy);

        hl_V_kernel->addWidget(labelKernelVersion);

        lb_V_kernel = new QLabel(gb_V_info);
        lb_V_kernel->setObjectName(QString::fromUtf8("lb_V_kernel"));
        sizePolicy1.setHeightForWidth(lb_V_kernel->sizePolicy().hasHeightForWidth());
        lb_V_kernel->setSizePolicy(sizePolicy1);

        hl_V_kernel->addWidget(lb_V_kernel);


        verticalLayoutVersionInfo->addLayout(hl_V_kernel);

        hl_V_complier = new QHBoxLayout();
        hl_V_complier->setObjectName(QString::fromUtf8("hl_V_complier"));
        hl_V_complier->setSizeConstraint(QLayout::SetDefaultConstraint);
        hl_V_complier->setContentsMargins(-1, -1, 0, -1);
        labelComplier = new QLabel(gb_V_info);
        labelComplier->setObjectName(QString::fromUtf8("labelComplier"));
        sizePolicy.setHeightForWidth(labelComplier->sizePolicy().hasHeightForWidth());
        labelComplier->setSizePolicy(sizePolicy);

        hl_V_complier->addWidget(labelComplier);

        lb_V_complier = new QLabel(gb_V_info);
        lb_V_complier->setObjectName(QString::fromUtf8("lb_V_complier"));
        sizePolicy1.setHeightForWidth(lb_V_complier->sizePolicy().hasHeightForWidth());
        lb_V_complier->setSizePolicy(sizePolicy1);

        hl_V_complier->addWidget(lb_V_complier);


        verticalLayoutVersionInfo->addLayout(hl_V_complier);

        hl_V_os_type = new QHBoxLayout();
        hl_V_os_type->setObjectName(QString::fromUtf8("hl_V_os_type"));
        labelOSType = new QLabel(gb_V_info);
        labelOSType->setObjectName(QString::fromUtf8("labelOSType"));
        sizePolicy.setHeightForWidth(labelOSType->sizePolicy().hasHeightForWidth());
        labelOSType->setSizePolicy(sizePolicy);

        hl_V_os_type->addWidget(labelOSType);

        lb_V_OS_type = new QLabel(gb_V_info);
        lb_V_OS_type->setObjectName(QString::fromUtf8("lb_V_OS_type"));
        sizePolicy1.setHeightForWidth(lb_V_OS_type->sizePolicy().hasHeightForWidth());
        lb_V_OS_type->setSizePolicy(sizePolicy1);

        hl_V_os_type->addWidget(lb_V_OS_type);


        verticalLayoutVersionInfo->addLayout(hl_V_os_type);

        hl_V_OS_version = new QHBoxLayout();
        hl_V_OS_version->setObjectName(QString::fromUtf8("hl_V_OS_version"));
        labelOSVersion = new QLabel(gb_V_info);
        labelOSVersion->setObjectName(QString::fromUtf8("labelOSVersion"));
        sizePolicy.setHeightForWidth(labelOSVersion->sizePolicy().hasHeightForWidth());
        labelOSVersion->setSizePolicy(sizePolicy);

        hl_V_OS_version->addWidget(labelOSVersion);

        lb_V_os_version = new QLabel(gb_V_info);
        lb_V_os_version->setObjectName(QString::fromUtf8("lb_V_os_version"));
        sizePolicy1.setHeightForWidth(lb_V_os_version->sizePolicy().hasHeightForWidth());
        lb_V_os_version->setSizePolicy(sizePolicy1);

        hl_V_OS_version->addWidget(lb_V_os_version);


        verticalLayoutVersionInfo->addLayout(hl_V_OS_version);


        verticalLayoutSystemInfo->addWidget(gb_V_info);

        tabWidget->addTab(tab_sys, QString());
        tab_OS = new QWidget();
        tab_OS->setObjectName(QString::fromUtf8("tab_OS"));
        verticalLayoutSystemInfo1 = new QVBoxLayout(tab_OS);
        verticalLayoutSystemInfo1->setObjectName(QString::fromUtf8("verticalLayoutSystemInfo1"));
        gb_OS_load = new QGroupBox(tab_OS);
        gb_OS_load->setObjectName(QString::fromUtf8("gb_OS_load"));
        sizePolicy.setHeightForWidth(gb_OS_load->sizePolicy().hasHeightForWidth());
        gb_OS_load->setSizePolicy(sizePolicy);
        gb_OS_load->setMinimumSize(QSize(420, 240));
        verticalLayoutOSLoad = new QVBoxLayout(gb_OS_load);
        verticalLayoutOSLoad->setObjectName(QString::fromUtf8("verticalLayoutOSLoad"));
        hl_OS_load_1 = new QHBoxLayout();
        hl_OS_load_1->setObjectName(QString::fromUtf8("hl_OS_load_1"));
        labelOSLoad1 = new QLabel(gb_OS_load);
        labelOSLoad1->setObjectName(QString::fromUtf8("labelOSLoad1"));
        sizePolicy.setHeightForWidth(labelOSLoad1->sizePolicy().hasHeightForWidth());
        labelOSLoad1->setSizePolicy(sizePolicy);

        hl_OS_load_1->addWidget(labelOSLoad1);

        lb_OS_load_1 = new QLabel(gb_OS_load);
        lb_OS_load_1->setObjectName(QString::fromUtf8("lb_OS_load_1"));
        sizePolicy1.setHeightForWidth(lb_OS_load_1->sizePolicy().hasHeightForWidth());
        lb_OS_load_1->setSizePolicy(sizePolicy1);

        hl_OS_load_1->addWidget(lb_OS_load_1);


        verticalLayoutOSLoad->addLayout(hl_OS_load_1);

        hl_OS_load_5 = new QHBoxLayout();
        hl_OS_load_5->setObjectName(QString::fromUtf8("hl_OS_load_5"));
        labelOSLoad5 = new QLabel(gb_OS_load);
        labelOSLoad5->setObjectName(QString::fromUtf8("labelOSLoad5"));
        sizePolicy.setHeightForWidth(labelOSLoad5->sizePolicy().hasHeightForWidth());
        labelOSLoad5->setSizePolicy(sizePolicy);

        hl_OS_load_5->addWidget(labelOSLoad5);

        lb_OS_load_5 = new QLabel(gb_OS_load);
        lb_OS_load_5->setObjectName(QString::fromUtf8("lb_OS_load_5"));
        sizePolicy1.setHeightForWidth(lb_OS_load_5->sizePolicy().hasHeightForWidth());
        lb_OS_load_5->setSizePolicy(sizePolicy1);

        hl_OS_load_5->addWidget(lb_OS_load_5);


        verticalLayoutOSLoad->addLayout(hl_OS_load_5);

        hl_OS_load_15 = new QHBoxLayout();
        hl_OS_load_15->setObjectName(QString::fromUtf8("hl_OS_load_15"));
        labelOSLoad15 = new QLabel(gb_OS_load);
        labelOSLoad15->setObjectName(QString::fromUtf8("labelOSLoad15"));
        sizePolicy.setHeightForWidth(labelOSLoad15->sizePolicy().hasHeightForWidth());
        labelOSLoad15->setSizePolicy(sizePolicy);

        hl_OS_load_15->addWidget(labelOSLoad15);

        lb_OS_load_15 = new QLabel(gb_OS_load);
        lb_OS_load_15->setObjectName(QString::fromUtf8("lb_OS_load_15"));
        sizePolicy1.setHeightForWidth(lb_OS_load_15->sizePolicy().hasHeightForWidth());
        lb_OS_load_15->setSizePolicy(sizePolicy1);

        hl_OS_load_15->addWidget(lb_OS_load_15);


        verticalLayoutOSLoad->addLayout(hl_OS_load_15);


        verticalLayoutSystemInfo1->addWidget(gb_OS_load);

        gb_OS_time = new QGroupBox(tab_OS);
        gb_OS_time->setObjectName(QString::fromUtf8("gb_OS_time"));
        sizePolicy.setHeightForWidth(gb_OS_time->sizePolicy().hasHeightForWidth());
        gb_OS_time->setSizePolicy(sizePolicy);
        gb_OS_time->setMinimumSize(QSize(420, 240));
        verticalLayoutOSTime = new QVBoxLayout(gb_OS_time);
        verticalLayoutOSTime->setObjectName(QString::fromUtf8("verticalLayoutOSTime"));
        hl_OS_run_time = new QHBoxLayout();
        hl_OS_run_time->setObjectName(QString::fromUtf8("hl_OS_run_time"));
        labelOSRunTime = new QLabel(gb_OS_time);
        labelOSRunTime->setObjectName(QString::fromUtf8("labelOSRunTime"));
        sizePolicy.setHeightForWidth(labelOSRunTime->sizePolicy().hasHeightForWidth());
        labelOSRunTime->setSizePolicy(sizePolicy);

        hl_OS_run_time->addWidget(labelOSRunTime);

        lb_OS_run_time = new QLabel(gb_OS_time);
        lb_OS_run_time->setObjectName(QString::fromUtf8("lb_OS_run_time"));
        sizePolicy1.setHeightForWidth(lb_OS_run_time->sizePolicy().hasHeightForWidth());
        lb_OS_run_time->setSizePolicy(sizePolicy1);

        hl_OS_run_time->addWidget(lb_OS_run_time);


        verticalLayoutOSTime->addLayout(hl_OS_run_time);

        hl_OS_free_time = new QHBoxLayout();
        hl_OS_free_time->setObjectName(QString::fromUtf8("hl_OS_free_time"));
        labelOSFreeTime = new QLabel(gb_OS_time);
        labelOSFreeTime->setObjectName(QString::fromUtf8("labelOSFreeTime"));
        sizePolicy.setHeightForWidth(labelOSFreeTime->sizePolicy().hasHeightForWidth());
        labelOSFreeTime->setSizePolicy(sizePolicy);

        hl_OS_free_time->addWidget(labelOSFreeTime);

        lb_OS_free_time = new QLabel(gb_OS_time);
        lb_OS_free_time->setObjectName(QString::fromUtf8("lb_OS_free_time"));
        sizePolicy1.setHeightForWidth(lb_OS_free_time->sizePolicy().hasHeightForWidth());
        lb_OS_free_time->setSizePolicy(sizePolicy1);

        hl_OS_free_time->addWidget(lb_OS_free_time);


        verticalLayoutOSTime->addLayout(hl_OS_free_time);


        verticalLayoutSystemInfo1->addWidget(gb_OS_time);

        tabWidget->addTab(tab_OS, QString());
        tab_CPU_data = new QWidget();
        tab_CPU_data->setObjectName(QString::fromUtf8("tab_CPU_data"));
        verticalLayoutCPUData = new QVBoxLayout(tab_CPU_data);
        verticalLayoutCPUData->setObjectName(QString::fromUtf8("verticalLayoutCPUData"));
        cv_CPU = new QChartView(tab_CPU_data);
        cv_CPU->setObjectName(QString::fromUtf8("cv_CPU"));
        cv_CPU->setMinimumSize(QSize(420, 500));

        verticalLayoutCPUData->addWidget(cv_CPU);

        tabWidget->addTab(tab_CPU_data, QString());
        tab_mem_data = new QWidget();
        tab_mem_data->setObjectName(QString::fromUtf8("tab_mem_data"));
        verticalLayoutMemData = new QVBoxLayout(tab_mem_data);
        verticalLayoutMemData->setObjectName(QString::fromUtf8("verticalLayoutMemData"));
        cv_mem = new QChartView(tab_mem_data);
        cv_mem->setObjectName(QString::fromUtf8("cv_mem"));
        cv_mem->setMinimumSize(QSize(420, 500));

        verticalLayoutMemData->addWidget(cv_mem);

        tabWidget->addTab(tab_mem_data, QString());
        tab_net_data = new QWidget();
        tab_net_data->setObjectName(QString::fromUtf8("tab_net_data"));
        verticalLayoutNetData = new QVBoxLayout(tab_net_data);
        verticalLayoutNetData->setObjectName(QString::fromUtf8("verticalLayoutNetData"));
        cv_net = new QChartView(tab_net_data);
        cv_net->setObjectName(QString::fromUtf8("cv_net"));
        cv_net->setMinimumSize(QSize(420, 500));

        verticalLayoutNetData->addWidget(cv_net);

        tabWidget->addTab(tab_net_data, QString());
        tab_disk_data = new QWidget();
        tab_disk_data->setObjectName(QString::fromUtf8("tab_disk_data"));
        verticalLayoutNetData1 = new QVBoxLayout(tab_disk_data);
        verticalLayoutNetData1->setObjectName(QString::fromUtf8("verticalLayoutNetData1"));
        cv_disk = new QChartView(tab_disk_data);
        cv_disk->setObjectName(QString::fromUtf8("cv_disk"));
        cv_disk->setMinimumSize(QSize(420, 500));

        verticalLayoutNetData1->addWidget(cv_disk);

        tabWidget->addTab(tab_disk_data, QString());
        tab_saved_device_data = new QWidget();
        tab_saved_device_data->setObjectName(QString::fromUtf8("tab_saved_device_data"));
        verticalLayoutSavedDeviceData = new QVBoxLayout(tab_saved_device_data);
        verticalLayoutSavedDeviceData->setObjectName(QString::fromUtf8("verticalLayoutSavedDeviceData"));
        tv_saved_device_data = new QTableView(tab_saved_device_data);
        tv_saved_device_data->setObjectName(QString::fromUtf8("tv_saved_device_data"));
        tv_saved_device_data->setAutoScroll(false);
        tv_saved_device_data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tv_saved_device_data->setAlternatingRowColors(true);
        tv_saved_device_data->setSelectionMode(QAbstractItemView::SingleSelection);
        tv_saved_device_data->setSelectionBehavior(QAbstractItemView::SelectRows);
        tv_saved_device_data->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tv_saved_device_data->setGridStyle(Qt::SolidLine);
        tv_saved_device_data->setCornerButtonEnabled(false);
        tv_saved_device_data->verticalHeader()->setVisible(false);

        verticalLayoutSavedDeviceData->addWidget(tv_saved_device_data);

        tabWidget->addTab(tab_saved_device_data, QString());
        tab_saved_OS_data = new QWidget();
        tab_saved_OS_data->setObjectName(QString::fromUtf8("tab_saved_OS_data"));
        verticalLayoutSavedOSData = new QVBoxLayout(tab_saved_OS_data);
        verticalLayoutSavedOSData->setObjectName(QString::fromUtf8("verticalLayoutSavedOSData"));
        tv_saved_OS_data = new QTableView(tab_saved_OS_data);
        tv_saved_OS_data->setObjectName(QString::fromUtf8("tv_saved_OS_data"));
        tv_saved_OS_data->setSizeIncrement(QSize(0, 0));
        tv_saved_OS_data->setAutoScroll(false);
        tv_saved_OS_data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tv_saved_OS_data->setAlternatingRowColors(true);
        tv_saved_OS_data->setSelectionMode(QAbstractItemView::SingleSelection);
        tv_saved_OS_data->setSelectionBehavior(QAbstractItemView::SelectRows);
        tv_saved_OS_data->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tv_saved_OS_data->setGridStyle(Qt::SolidLine);
        tv_saved_OS_data->setCornerButtonEnabled(false);
        tv_saved_OS_data->verticalHeader()->setVisible(false);

        verticalLayoutSavedOSData->addWidget(tv_saved_OS_data);

        tabWidget->addTab(tab_saved_OS_data, QString());
        tab_saved_CPU_data = new QWidget();
        tab_saved_CPU_data->setObjectName(QString::fromUtf8("tab_saved_CPU_data"));
        verticalLayoutSavedCPUData = new QVBoxLayout(tab_saved_CPU_data);
        verticalLayoutSavedCPUData->setObjectName(QString::fromUtf8("verticalLayoutSavedCPUData"));
        tv_saved_CPU_data = new QTableView(tab_saved_CPU_data);
        tv_saved_CPU_data->setObjectName(QString::fromUtf8("tv_saved_CPU_data"));
        tv_saved_CPU_data->setAutoScroll(false);
        tv_saved_CPU_data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tv_saved_CPU_data->setAlternatingRowColors(true);
        tv_saved_CPU_data->setSelectionMode(QAbstractItemView::SingleSelection);
        tv_saved_CPU_data->setSelectionBehavior(QAbstractItemView::SelectRows);
        tv_saved_CPU_data->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tv_saved_CPU_data->setGridStyle(Qt::SolidLine);
        tv_saved_CPU_data->setCornerButtonEnabled(false);
        tv_saved_CPU_data->verticalHeader()->setVisible(false);

        verticalLayoutSavedCPUData->addWidget(tv_saved_CPU_data);

        tabWidget->addTab(tab_saved_CPU_data, QString());
        tab_saved_mem_data = new QWidget();
        tab_saved_mem_data->setObjectName(QString::fromUtf8("tab_saved_mem_data"));
        verticalLayoutSavedMemData = new QVBoxLayout(tab_saved_mem_data);
        verticalLayoutSavedMemData->setObjectName(QString::fromUtf8("verticalLayoutSavedMemData"));
        tv_saved_mem_data = new QTableView(tab_saved_mem_data);
        tv_saved_mem_data->setObjectName(QString::fromUtf8("tv_saved_mem_data"));
        tv_saved_mem_data->setAutoScroll(false);
        tv_saved_mem_data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tv_saved_mem_data->setAlternatingRowColors(true);
        tv_saved_mem_data->setSelectionMode(QAbstractItemView::SingleSelection);
        tv_saved_mem_data->setSelectionBehavior(QAbstractItemView::SelectRows);
        tv_saved_mem_data->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tv_saved_mem_data->setGridStyle(Qt::SolidLine);
        tv_saved_mem_data->setCornerButtonEnabled(false);
        tv_saved_mem_data->verticalHeader()->setVisible(false);

        verticalLayoutSavedMemData->addWidget(tv_saved_mem_data);

        tabWidget->addTab(tab_saved_mem_data, QString());
        tab_saved_net_data = new QWidget();
        tab_saved_net_data->setObjectName(QString::fromUtf8("tab_saved_net_data"));
        verticalLayoutSavedNetData = new QVBoxLayout(tab_saved_net_data);
        verticalLayoutSavedNetData->setObjectName(QString::fromUtf8("verticalLayoutSavedNetData"));
        tv_saved_net_data = new QTableView(tab_saved_net_data);
        tv_saved_net_data->setObjectName(QString::fromUtf8("tv_saved_net_data"));
        tv_saved_net_data->setAutoScroll(false);
        tv_saved_net_data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tv_saved_net_data->setAlternatingRowColors(true);
        tv_saved_net_data->setSelectionMode(QAbstractItemView::SingleSelection);
        tv_saved_net_data->setSelectionBehavior(QAbstractItemView::SelectRows);
        tv_saved_net_data->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tv_saved_net_data->setGridStyle(Qt::SolidLine);
        tv_saved_net_data->setCornerButtonEnabled(false);
        tv_saved_net_data->verticalHeader()->setVisible(false);

        verticalLayoutSavedNetData->addWidget(tv_saved_net_data);

        tabWidget->addTab(tab_saved_net_data, QString());
        tab_saved_disk_data = new QWidget();
        tab_saved_disk_data->setObjectName(QString::fromUtf8("tab_saved_disk_data"));
        verticalLayoutSavedDiskData = new QVBoxLayout(tab_saved_disk_data);
        verticalLayoutSavedDiskData->setObjectName(QString::fromUtf8("verticalLayoutSavedDiskData"));
        tv_saved_disk_data = new QTableView(tab_saved_disk_data);
        tv_saved_disk_data->setObjectName(QString::fromUtf8("tv_saved_disk_data"));
        tv_saved_disk_data->setAutoScroll(false);
        tv_saved_disk_data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tv_saved_disk_data->setAlternatingRowColors(true);
        tv_saved_disk_data->setSelectionMode(QAbstractItemView::SingleSelection);
        tv_saved_disk_data->setSelectionBehavior(QAbstractItemView::SelectRows);
        tv_saved_disk_data->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tv_saved_disk_data->setGridStyle(Qt::SolidLine);
        tv_saved_disk_data->setCornerButtonEnabled(false);
        tv_saved_disk_data->verticalHeader()->setVisible(false);

        verticalLayoutSavedDiskData->addWidget(tv_saved_disk_data);

        tabWidget->addTab(tab_saved_disk_data, QString());
        tab_setting = new QWidget();
        tab_setting->setObjectName(QString::fromUtf8("tab_setting"));
        pb_save = new QPushButton(tab_setting);
        pb_save->setObjectName(QString::fromUtf8("pb_save"));
        pb_save->setGeometry(QRect(160, 180, 200, 200));
        pb_save->setMinimumSize(QSize(200, 200));
        le_fresh_time = new QLineEdit(tab_setting);
        le_fresh_time->setObjectName(QString::fromUtf8("le_fresh_time"));
        le_fresh_time->setGeometry(QRect(590, 180, 381, 121));
        le_fresh_time->setAlignment(Qt::AlignCenter);
        pb_confirm_fresh = new QPushButton(tab_setting);
        pb_confirm_fresh->setObjectName(QString::fromUtf8("pb_confirm_fresh"));
        pb_confirm_fresh->setGeometry(QRect(590, 310, 381, 71));
        tabWidget->addTab(tab_setting, QString());

        horizontalLayoutTab->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lb_user_name->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        lb_password->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        pb_confirm_login->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        gb_device_info->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\344\277\241\346\201\257", nullptr));
        labelDeviceName->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\345\220\215\347\247\260:", nullptr));
        lb_device_name->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelDiskSize->setText(QCoreApplication::translate("MainWindow", "\347\243\201\347\233\230\346\200\273\345\256\271\351\207\217:", nullptr));
        lb_device_disk->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelIPv4->setText(QCoreApplication::translate("MainWindow", "IPv4\345\234\260\345\235\200:", nullptr));
        lb_device_IPv4->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelIPv6->setText(QCoreApplication::translate("MainWindow", "IPv6\345\234\260\345\235\200:", nullptr));
        lb_device_IPv6->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelMAC->setText(QCoreApplication::translate("MainWindow", "MAC\345\234\260\345\235\200:", nullptr));
        lb_device_MAC->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelMem->setText(QCoreApplication::translate("MainWindow", "\345\206\205\345\255\230\346\200\273\351\207\217:", nullptr));
        lb_device_mem->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        gb_CPU_info->setTitle(QCoreApplication::translate("MainWindow", "CPU\344\277\241\346\201\257", nullptr));
        labelCPUModel->setText(QCoreApplication::translate("MainWindow", "CPU\345\236\213\345\217\267:", nullptr));
        lb_CPU_model->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelCPUCores->setText(QCoreApplication::translate("MainWindow", "CPU\346\240\270\346\225\260:", nullptr));
        lb_CPU_num->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelCPUFreq->setText(QCoreApplication::translate("MainWindow", "CPU\351\242\221\347\216\207:", nullptr));
        lb_CPU_freq->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelCPUMHZ->setText(QCoreApplication::translate("MainWindow", "MHZ", nullptr));
        labelCPUBuf->setText(QCoreApplication::translate("MainWindow", "\347\274\223\345\255\230\345\244\247\345\260\217:", nullptr));
        lb_CPU_buf->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        gb_V_info->setTitle(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254\344\277\241\346\201\257", nullptr));
        labelKernelVersion->setText(QCoreApplication::translate("MainWindow", "\345\206\205 \346\240\270 \347\211\210 \346\234\254:", nullptr));
        lb_V_kernel->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelComplier->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\257\221\345\231\250\347\211\210\346\234\254:", nullptr));
        lb_V_complier->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelOSType->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237:", nullptr));
        lb_V_OS_type->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelOSVersion->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\347\211\210\346\234\254:", nullptr));
        lb_V_os_version->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_sys), QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\344\277\241\346\201\257", nullptr));
        gb_OS_load->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\350\264\237\350\275\275", nullptr));
        labelOSLoad1->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\2371\345\210\206\351\222\237\345\206\205\345\271\263\345\235\207\350\264\237\350\275\275:", nullptr));
        lb_OS_load_1->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelOSLoad5->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\2375\345\210\206\351\222\237\345\206\205\345\271\263\345\235\207\350\264\237\350\275\275:", nullptr));
        lb_OS_load_5->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelOSLoad15->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\23715\345\210\206\351\222\237\345\206\205\345\271\263\345\235\207\350\264\237\350\275\275:", nullptr));
        lb_OS_load_15->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        gb_OS_time->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\346\227\266\351\227\264", nullptr));
        labelOSRunTime->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\350\277\220\350\241\214\346\227\266\351\227\264:", nullptr));
        lb_OS_run_time->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        labelOSFreeTime->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\347\251\272\351\227\262\346\227\266\351\227\264:", nullptr));
        lb_OS_free_time->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_OS), QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_CPU_data), QCoreApplication::translate("MainWindow", "CPU\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_mem_data), QCoreApplication::translate("MainWindow", "\345\206\205\345\255\230\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_net_data), QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_disk_data), QCoreApplication::translate("MainWindow", "\347\243\201\347\233\230\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_saved_device_data), QCoreApplication::translate("MainWindow", "\345\267\262\344\277\235\345\255\230\347\263\273\347\273\237\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_saved_OS_data), QCoreApplication::translate("MainWindow", "\345\267\262\344\277\235\345\255\230\346\223\215\344\275\234\347\263\273\347\273\237\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_saved_CPU_data), QCoreApplication::translate("MainWindow", "\345\267\262\344\277\235\345\255\230CPU\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_saved_mem_data), QCoreApplication::translate("MainWindow", "\345\267\262\344\277\235\345\255\230\345\206\205\345\255\230\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_saved_net_data), QCoreApplication::translate("MainWindow", "\345\267\262\344\277\235\345\255\230\347\275\221\347\273\234\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_saved_disk_data), QCoreApplication::translate("MainWindow", "\345\267\262\344\277\235\345\255\230\347\243\201\347\233\230\346\225\260\346\215\256", nullptr));
        pb_save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\210\260\346\225\260\346\215\256\345\272\223", nullptr));
        le_fresh_time->setText(QString());
        pb_confirm_fresh->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_setting), QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
