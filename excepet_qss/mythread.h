#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    int start();
    void stop();
signals:

public slots:

protected:
    virtual void run();

private:
    bool m_bStopThreadFlag;
};

#endif // MYTHREAD_H
