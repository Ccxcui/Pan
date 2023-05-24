#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("C:\\Users\\86187\\Desktop\\cloud.db");
//    m_db.setUserName();
//    m_db.setPassword();
    bool ret = m_db.open();
    if (!ret)
    {
        QMessageBox::critical(this, "open db", "open db failed");
    }
    else
    {
        QMessageBox::information(this, "open db", "open db ok!");
    }
}

Widget::~Widget()
{
    delete ui;
    m_db.close();
}

void Widget::on_select_pb_clicked()
{
    QSqlQuery query;
    query.exec("select * from usrInfo");
    while (query.next())
    {
        QString data = QString("%1,%2,%3").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString());
        ui->textEdit->append(data);
    }
}
