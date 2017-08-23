#include "teamsrecord.h"
#include "ui_teamsrecord.h"


TeamsRecord::TeamsRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamsRecord)
{
    ui->setupUi(this);



}

TeamsRecord::~TeamsRecord()
{
    delete ui;
}

void TeamsRecord::onLoadTable()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT Team, Wins  FROM [dbo].[tbl_Record]");



         ui->tableView->setModel(model);
         qDebug() << model->lastError().text();

}



void TeamsRecord::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString value = ui->tableView->model()->data(index).toString();
    QString team, wins, loses, ties, pts;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM [dbo].[tbl_Record] WHERE Team='"+value+"' or Wins='"+value+"' ");

    if(qry.exec())
    {
        while(qry.next())
        {
            team = qry.value(0).toString();
            wins = qry.value(1).toString();
            loses = qry.value(2).toString();
            ties = qry.value(3).toString();
            pts = qry.value(4).toString();
        }
    }
    emit transferData(team, wins, loses, ties, pts);
}
