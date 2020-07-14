#include "mywidget.h"
#include "ui_mywidget.h"





MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->ctrlWidget->setProperty("mandatoryField", "idl");
    m_pThread = new MyThread(this);
    m_pThread->start();
}

MyWidget::~MyWidget()
{
    m_pThread->stop();
    delete ui;
}

void MyWidget::on_startButton_clicked()
{
    ui->ctrlWidget->setProperty("mandatoryField", "active");
    ui->ctrlWidget->style()->unpolish(ui->ctrlWidget);
    ui->ctrlWidget->style()->polish(ui->ctrlWidget);
}

void MyWidget::on_stopButton_clicked()
{
    ui->ctrlWidget->setProperty("mandatoryField", "warnning");
    ui->ctrlWidget->style()->unpolish(ui->ctrlWidget);
    ui->ctrlWidget->style()->polish(ui->ctrlWidget);
}
