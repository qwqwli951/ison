#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   
    MainWindow w;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    w.setWindowTitle(QObject::tr("��ѯͼ����Ϣ"));
    w.setFixedSize( w.width (),w.height ());//�̶����ڴ�С
    w.show();   
    return a.exec();
}
