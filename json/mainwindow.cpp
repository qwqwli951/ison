#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_chaxun_clicked()
{
    if(ui->ID->text()!="")
    {
    S1="https://api.douban.com/v2/book/";
    S2=ui->ID->text();  //��ȡ�����ISBN
    //����QTextCodec������ʾ����
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QNetworkRequest request;
    request.setUrl(QUrl(S1+S2));
    manager = new QNetworkAccessManager(this);  //�½�QNetworkAccessManager����
    connect(manager,SIGNAL(finished(QNetworkReply*)),  //�����źźͲ�
                this,SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(request)); //��������
    }
    else{
        //�������ȷ����������Ի���
        QMessageBox::information(0,"error!",QString(QObject::tr("��û������ISBN\n���������롣")));
    }
}
void MainWindow::replyFinished(QNetworkReply *reply)
{
        QString all = reply->readAll();
        /*if("bad isbn"==all)  //������������رմ��ڲ���������Ի���
        {
            QMessageBox::information(0, "error!",QString(QObject::tr("�����ISBN�д���\n����������")));
            ui->ID->clear();
            return;
        }
        else
        {*/
            my.setFixedSize( my.width (),my.height ());//�̶����ڴ�С
            my.setDoc(all);
            if(!my.dai())
            {
                QMessageBox::information(0, "error!",QString(QObject::tr("�����ISBN�д���\n����������")));
                ui->ID->clear();
                return;
            }
            else
                my.show();

        reply->deleteLater();   //���Ҫ�ͷ�reply����
}

