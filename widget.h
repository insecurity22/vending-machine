#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    int money{0}; // "money{0}" is better than "money = 0" in C++.
    void changeMoney(int n); // Make changeMoney function

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbcoffee_clicked();

    void on_pbtea_clicked();

    void on_pbgongcha_clicked();

    void on_pbreturn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
