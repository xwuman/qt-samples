#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QTextCodec>
#include <QString>
#include <QFile>

//#pragma execution_character_set("utf-8")


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->label_2->setText(QStringLiteral("2.这是源码中的中文字符串"));//
    ui->label_3->setText("3.这是源码中的中文字符串");
    ui->label_4->setText(QString::fromUtf8("4.这是源码中的中文字符串"));
    ui->label_5->setText(QString::fromLatin1("5.这是源码中的中文字符串"));
    ui->label_6->setText(QString::fromLocal8Bit("6.这是源码中的中文字符串"));
    ui->label_7->setText(tr("7.这是源码中的中文字符串"));


}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::api_func1(const char *ch)
{
    QString str = QString::fromUtf8(ch);
    ui->testButton->setText(str);
}

void MainWidget::api_func2(QByteArray &ba)
{
    QString str = QString::fromUtf8(ba);
    ui->testButton->setText(str);
}

void MainWidget::on_testButton_clicked()
{
    QString test = ui->label_3->text();
    QByteArray ba = test.toUtf8();
    // 调用api函数（函数需要二进制的参数）
    api_func1(ba.data());
    api_func2(ba);
}

void MainWidget::on_test2Button_clicked()
{
    //
    QFile f(":/text中文.data");
    if (f.open(QFile::ReadOnly))
    {
        QByteArray ba = f.readAll();
       ui->label_8->setText(QString::fromLocal8Bit(ba));
       // ui->label_8->setText(ba);
        f.close();
    }
}
