#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();


private slots:
    void on_testButton_clicked();
    void on_test2Button_clicked();

protected:
    void api_func1(const char *ch);
    void api_func2(QByteArray &ba);
private:
    Ui::MainWidget *ui;

};

#endif // MAINWIDGET_H
