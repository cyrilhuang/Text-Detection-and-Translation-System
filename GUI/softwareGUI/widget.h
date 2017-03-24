#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton0_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QString path;
    bool flag = false;
};

#endif // WIDGET_H
