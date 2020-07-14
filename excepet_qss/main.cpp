#include "mywidget.h"
#include <QApplication>
#include <QDir>
int setSkin(const QString &skinName)
{
    QString currentSkinDir = QString("%1/%2")
            .arg(QApplication::applicationDirPath()).arg(skinName);
    QString styleFilePath = currentSkinDir + "/default.qss";
    QDir::setCurrent(currentSkinDir);
    QFile file(styleFilePath);
    if (file.open(QFile::ReadOnly))
    {
        QString styleSheet = file.readAll();
        qApp->setStyleSheet(styleSheet);
        file.close();
        //CxLog_Err(QString("App::setSkin ok. styleFilePath=%1").arg(styleFilePath));
    }
    else
    {

    }
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setSkin("black");
    MyWidget w;
    w.show();

    return a.exec();
}
