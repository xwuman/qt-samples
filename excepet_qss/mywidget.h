#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mythread.h"

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
private:
    Ui::MyWidget *ui;
    MyThread *m_pThread;
};

#endif // MYWIDGET_H
