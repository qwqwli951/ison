#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtNetwork>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setDoc(QString);
    bool dai();
    bool B;
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
