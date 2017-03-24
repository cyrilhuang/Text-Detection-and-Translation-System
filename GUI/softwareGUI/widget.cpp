#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QTextStream>
#include <cstring>
#include <string>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton0_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Open Image"));
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("Image Files(*.jpg *.png)"));
    if(fileDialog->exec() == QDialog::Accepted) {
            path = fileDialog->selectedFiles()[0];
            QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
    } else {
            QMessageBox::information(NULL, tr("Path"), tr("You didn't select any pictures."));
    }
}

void Widget::on_pushButton1_clicked()
{
    if(path == NULL) {
        QMessageBox::information(NULL, tr("choose a picture"), tr("You didn't select any pictures."));
    }
    else {
//        QObject *parent;
//        QString program = "/home/zhangwbnn/code/textDetection2/TestDetection";
//        QStringList arguments;
//        arguments << path;
//        QProcess *myProcess = new QProcess(parent);
//        myProcess->start("subl", arguments);

        char sys[200];
        strcat(sys, "./TestDetection ");
        QByteArray ba = path.toLatin1();
        const char *arg = ba.data();

        strcat(sys,arg);
        //qDebug()<<sys;
        system(sys);

        flag = true;
    }
}

void Widget::on_pushButton2_clicked()
{
    QMessageBox::information(NULL, tr("help"), tr("first, you should push \"choose picture\" to choose a picture;\n"
                                                  "then, push \"detect text\" to detect text.\n"
                                                  "next, you can show text recognization and traslating results"));
}

void Widget::on_pushButton_clicked()
{
    if(flag) {
        QFile fileIn("/home/zhangwbnn/code/Text-Detection/textDetection/resource/result.txt");
        if(!fileIn.open(QIODevice::ReadOnly) )
        {
            QMessageBox::warning(this, tr("open text file"),
                                 tr("falied：") + fileIn.errorString());
            return;
        }

        QTextStream tsIn(&fileIn);
        const QString & str = tsIn.readAll();

        ui->textBrowser1->clear();

        ui->textBrowser1->append(str);
    }
    else {
        QMessageBox::information(NULL, tr("detect picture"), tr("You didn't detect pictures."));
    }


}

void Widget::on_pushButton_2_clicked()
{

    if(flag) {

        char sys[100] = "python /home/zhangwbnn/code/Text-Detection/api.py";
        system(sys);
        qDebug()<<"py f";

        QFile fileIn("/home/zhangwbnn/code/Text-Detection/textDetection/resource/tran.txt");
        if(!fileIn.open(QIODevice::ReadOnly) )
        {
            QMessageBox::warning(this, tr("open text file"),
                                 tr("falied：") + fileIn.errorString());
            return;
        }
        qDebug()<<"file";
        QTextStream tsIn(&fileIn);
        const QString & str = tsIn.readAll();

        ui->textBrowser2->clear();

        ui->textBrowser2->append(str);
        qDebug()<<"finish";
    }
    else {
        QMessageBox::information(NULL, tr("detect picture"), tr("You didn't detect pictures."));
    }
}
