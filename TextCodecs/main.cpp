#include "mainwidget.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*On Windows, the codec will be based on a system locale.
     * On Unix systems, the codec will might fall back to using the iconv
     * library if no builtin codec for the locale can be found.*/
   QTextCodec *codec = QTextCodec::codecForName("gbk");
  // QTextCodec *codec = QTextCodec::codecForName("utf8");
   QTextCodec::setCodecForLocale(codec);
    MainWidget w;
    w.show();

    return a.exec();
}
