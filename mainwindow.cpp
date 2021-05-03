#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <algoritmlar.h>
#include <QDateTime>
#include <QtAlgorithms>
using namespace std;
int arr[10000],brr[10000];

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

void MainWindow::on_pushButton_6_clicked()
{
    ui->listWidget->clear();
    for(int i=0;i<10000;i++){
        arr[i]=rand();
        brr[i]=arr[i];
        ui->listWidget->addItem(QString::number(arr[i]));
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox msg;
    msg.setWindowTitle("Tozalash");
    msg.setText("Sonlarni tozalashni xohlaysizmi?");
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret=msg.exec();

    switch(ret){
        case QMessageBox::Ok:
            ui->listWidget->clear();
            break;
        default:
            break;
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msg;
    msg.setWindowTitle("Chiqish");
    msg.setText("Dasturdan chiqishni xohlaysizmi?");
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret=msg.exec();

    switch(ret){
        case QMessageBox::Ok:
            this->close();
            break;
        default:
            break;
    }
}


void MainWindow::on_pushButton_clicked()
{
    QDateTime t_start=QDateTime::currentDateTime();
    QDateTime t_end;
    quickSort(arr, 0, 10000);
    t_end=QDateTime::currentDateTime();
    ui->listWidget->clear();
    for(int i=0;i<10000;i++){
        ui->listWidget->addItem(QString::number(arr[i]));
    }
    qint64 ms = t_start.msecsTo(t_end);
    ui->label_4->setText(QString::number(ms)+" ms");
}

void MainWindow::on_pushButton_2_clicked()
{
    QDateTime t_start=QDateTime::currentDateTime();
    QDateTime t_end;

    bubbleSort(arr, 10000);
    t_end=QDateTime::currentDateTime();
    ui->listWidget->clear();
    for(int i=0;i<10000;i++){
        ui->listWidget->addItem(QString::number(arr[i]));
    }

    qint64 ms = t_start.msecsTo(t_end);
    ui->label_5->setText(QString::number(ms)+" ms");
}

void MainWindow::on_pushButton_3_clicked()
{
    QDateTime t_start=QDateTime::currentDateTime();
    QDateTime t_end;

    mergeSort(arr, 0, 10000);
    t_end=QDateTime::currentDateTime();
    ui->listWidget->clear();
    for(int i=0;i<10000;i++){
        ui->listWidget->addItem(QString::number(arr[i]));
    }

    qint64 ms = t_start.msecsTo(t_end);
    ui->label_6->setText(QString::number(ms)+" ms");
}

void MainWindow::on_pushButton_7_clicked()
{
    QDateTime t_start=QDateTime::currentDateTime();
    QDateTime t_end;

    qSort(arr,arr+10000);
    t_end=QDateTime::currentDateTime();
    ui->listWidget->clear();
    for(int i=0;i<10000;i++){
        ui->listWidget->addItem(QString::number(arr[i]));
    }

    qint64 ms = t_start.msecsTo(t_end);
    ui->label_8->setText(QString::number(ms)+" ms");
}

void MainWindow::on_pushButton_8_clicked()
{
    QDateTime t_start=QDateTime::currentDateTime();
    QDateTime t_end;

    selectionSort(arr,10000);
    t_end=QDateTime::currentDateTime();
    ui->listWidget->clear();
    for(int i=0;i<10000;i++){
        ui->listWidget->addItem(QString::number(arr[i]));
    }

    qint64 ms = t_start.msecsTo(t_end);
    ui->label_10->setText(QString::number(ms)+" ms");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->listWidget->clear();
    for(int i=0;i<10000;i++){
        arr[i]=brr[i];
        ui->listWidget->addItem(QString::number(arr[i]));
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    QDateTime t_start=QDateTime::currentDateTime();
    QDateTime t_end;

    insertionSort(arr,10000);
    t_end=QDateTime::currentDateTime();
    ui->listWidget->clear();
    for(int i=0;i<10000;i++){
        ui->listWidget->addItem(QString::number(arr[i]));
    }

    qint64 ms = t_start.msecsTo(t_end);
    ui->label_12->setText(QString::number(ms)+" ms");
}
