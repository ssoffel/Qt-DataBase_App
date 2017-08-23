#include "login_window.h"
#include "ui_login_window.h"

Login_Window::Login_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login_Window)
{
    ui->setupUi(this);




    //A QPixmap can easily be displayed on the screen using QLabel or one of QAbstractButton's subclasses
    QPixmap pic("C:/Users/Scott/Documents/QT/Database_App/images.jpg");
    ui->Label_picture->setPixmap(pic);




}

Login_Window::~Login_Window()
{
    delete ui;
}



void Login_Window::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "ssoffel" && password == "Altessa1")
    {


          DB_Connection::instance();

                team.setModal(true);
                this->hide();
                team.exec();
                qDebug() << "Connected...";









     }
    else
    {
       ui->lineEdit_password->clear();
       ui->lineEdit_username->clear();
       ui->label_status->setText("Login failed");

    }
}
