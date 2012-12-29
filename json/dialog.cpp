#include "dialog.h"
#include "ui_dialog.h"
#include <QTextCodec.h>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptValueIterator>
#include <qmessagebox.h>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
void Dialog::setDoc(QString all)
{

    QScriptValue value;
    QScriptEngine engine;
    value = engine.evaluate("value = " + QString(all));
    QScriptValueIterator it(value);
    while (it.hasNext()) {

       it.next();

       if("msg"==it.name()&& "book_not_found"== it.value().toString())
       {
             B=false;
             return;
       }
       else
       {
           B=true;
       if("title"==it.name())ui->title->setText(it.value().toString());
       if("author"==it.name())ui->author->setText(it.value().toString());
       if("alt"==it.name())ui->alt->setText(it.value().toString());
       if("id"==it.name())ui->shuID->setText(it.value().toString());
       if("binding"==it.name())ui->binding->setText(it.value().toString());
       if("isbn10"==it.name())ui->isbn10->setText(it.value().toString());
       if("isbn13"==it.name())ui->isbn13->setText(it.value().toString());
       if("pages"==it.name())ui->pages->setText(it.value().toString());
       if("price"==it.name())ui->price->setText(it.value().toString());
       if("publisher"==it.name())ui->publisher->setText(it.value().toString());
       if("pubdate"==it.name())ui->pubdate->setText(it.value().toString());
       if("summary"==it.name())ui->summary->setText(it.value().toString());
       }
    }
}
bool Dialog:: dai()
{
    return B;
}

Dialog::~Dialog()
{
    delete ui;
}

