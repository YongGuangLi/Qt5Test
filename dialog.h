#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QThread>
#include <QSqlDatabase>
#include <QEvent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    bool eventFilter(QObject *o, QEvent *e);
private slots:
    void slot_calculate(int i);
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    bool running;
};

#endif // DIALOG_H
