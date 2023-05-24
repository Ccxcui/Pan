#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_select_pb_clicked();

private:
    Ui::Widget *ui;
    //连接数据库对象
    QSqlDatabase m_db;
};

#endif // WIDGET_H
