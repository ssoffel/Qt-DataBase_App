#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include "db_connection.h"
#include "teaminfo.h"

namespace Ui {
class Login_Window;
}

class DB_Connection;

class Login_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login_Window(QWidget *parent = 0);
    ~Login_Window();



private slots:
    void on_pushButton_clicked();

private:
    Ui::Login_Window *ui;

    TeamInfo team;


};

#endif // LOGIN_WINDOW_H
