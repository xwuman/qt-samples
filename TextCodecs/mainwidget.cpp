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
    ui->label_2->setText(QStringLiteral("2.����Դ���е������ַ���"));//
    ui->label_3->setText("3.����Դ���е������ַ���");
    ui->label_4->setText(QString::fromUtf8("4.����Դ���е������ַ���"));
    ui->label_5->setText(QString::fromLatin1("5.����Դ���е������ַ���"));
    ui->label_6->setText(QString::fromLocal8Bit("6.����Դ���е������ַ���"));
    ui->label_7->setText(tr("7.����Դ���е������ַ���"));


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
    // ����api������������Ҫ�����ƵĲ�����
    api_func1(ba.data());
    api_func2(ba);
}

void MainWidget::on_test2Button_clicked()
{
    //
    QFile f(":/text����.data");
    if (f.open(QFile::ReadOnly))
    {
        QByteArray ba = f.readAll();
       ui->label_8->setText(QString::fromLocal8Bit(ba));
       // ui->label_8->setText(ba);
        f.close();
    }
}
