#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),running(true),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::fromLocal8Bit("中国"));
    this->installEventFilter(this);
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::eventFilter(QObject *o, QEvent *e)
{
    if(QEvent::Close == e->type())
        running = false;

    return QObject::eventFilter(o, e);
}

void Dialog::slot_calculate(int i)
{
    qDebug()<<QThread::currentThreadId();
    while (running)
    {
        ++i;
        qDebug()<<i;
        QCoreApplication::processEvents();
    }
}

void Dialog::on_pushButton_clicked()
{
    QMetaObject::invokeMethod(this, "slot_calculate", Qt::QueuedConnection, Q_ARG(int, 1));
    qDebug()<<QThread::currentThreadId();
}
