/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton0;
    QPushButton *pushButton1;
    QLabel *label;
    QPushButton *pushButton2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QTextBrowser *textBrowser1;
    QTextBrowser *textBrowser2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(971, 599);
        pushButton0 = new QPushButton(Widget);
        pushButton0->setObjectName(QStringLiteral("pushButton0"));
        pushButton0->setGeometry(QRect(400, 160, 141, 31));
        pushButton1 = new QPushButton(Widget);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setGeometry(QRect(400, 230, 141, 31));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 550, 561, 41));
        pushButton2 = new QPushButton(Widget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(870, 10, 81, 21));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 300, 141, 31));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 300, 141, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 70, 631, 61));
        textBrowser1 = new QTextBrowser(Widget);
        textBrowser1->setObjectName(QStringLiteral("textBrowser1"));
        textBrowser1->setGeometry(QRect(150, 350, 256, 192));
        textBrowser2 = new QTextBrowser(Widget);
        textBrowser2->setObjectName(QStringLiteral("textBrowser2"));
        textBrowser2->setGeometry(QRect(560, 350, 256, 192));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton0->setText(QApplication::translate("Widget", "choose a picture", 0));
        pushButton1->setText(QApplication::translate("Widget", "detect text", 0));
        label->setText(QApplication::translate("Widget", "copyright@software class    ZhangWenbin  ChenQingrong  HuangSheng", 0));
        pushButton2->setText(QApplication::translate("Widget", "help", 0));
        pushButton->setText(QApplication::translate("Widget", "show text", 0));
        pushButton_2->setText(QApplication::translate("Widget", "traslate text", 0));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Text Detection, Recognization, and Translation System</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
