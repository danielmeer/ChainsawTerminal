#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QtSerialPort/QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_serialPortRefreshButton_clicked()
{
    ui->serialPortList->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->serialPortList->addItem(info.portName());
    }
}

void MainWindow::on_serialPortConnectButton_clicked()
{
    QListWidgetItem *selectedItem = ui->serialPortList->currentItem();

    if (!selectedItem) {
        QMessageBox msgBox;
        msgBox.setText("No serial port selected!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}
