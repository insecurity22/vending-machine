#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Initialize
    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbgongcha->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

// 1. If you push money button, increase money.
// 2. setEnabled(true), setEnabled(false)
void Widget::changeMoney(int valueforadd) {

    money += valueforadd;

    if(money >= 100) ui->pbcoffee->setEnabled(true); // coffee
    else ui->pbcoffee->setEnabled(false);

    if(money >= 150) ui->pbtea->setEnabled(true); // tea
    else ui->pbtea->setEnabled(false);

    if(money >= 200) ui->pbgongcha->setEnabled(true); // gongcha
    else ui->pbgongcha->setEnabled(false);

    ui->lcdNumber->display(QString::number(money));
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbtea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbgongcha_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbreturn_clicked()
{
    int value;
    QMessageBox msgBox;

    QString str = "500 : "; // If 1250 won,
    value = money / 500;
    str.append(QString::number(value)); // 500, 2
    money -= (500 * value);

    str.append("\n100 : ");
    value = money / 100;
    str.append(QString::number(value)); // 100, 2
    money -= (100 * value);

    str.append("\n50 : ");
    value = money / 50;
    str.append(QString::number(value)); // 50, 1
    money -= (50 * value);

    str.append("\n10 : ");
    value = money / 10;
    str.append(QString::number(value));
    money -= (10 * value);

    msgBox.setInformativeText(str);
    msgBox.exec();

    money = 0;
    ui->lcdNumber->display(QString::number(money));
    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbgongcha->setEnabled(false);
}
