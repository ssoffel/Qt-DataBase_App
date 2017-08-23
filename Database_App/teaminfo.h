#ifndef TEAMINFO_H
#define TEAMINFO_H

#include <QDialog>
#include "db_connection.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include "tableview.h"
#include "teamsrecord.h"
#include <QListView>


namespace Ui {
class TeamInfo;
}

class TeamInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TeamInfo(QWidget *parent = 0);
    ~TeamInfo();



signals:
    void LoadTable();
    void LoadRecordsTable();


public slots:
    void onTransferData(QString, QString, QString, QString, QString);


private slots:
    void on_pushButton_Save_clicked();

    void on_pushButton_Exit_clicked();


    void on_pushButton_Edit_clicked();

    void on_pushButton_Delete_clicked();

    void on_pushButton_LoadTable_clicked();

    void on_pushButton_Load_Records_Table_clicked();

    void on_pushButton_List_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();





private:
    Ui::TeamInfo *ui;
  //  DB_Connection conn;
    TableView* TV;
    TeamsRecord* TR;
    QListView* view;

};

#endif // TEAMINFO_H
