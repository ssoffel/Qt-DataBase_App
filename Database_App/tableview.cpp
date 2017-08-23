#include "tableview.h"
#include "ui_tableview.h"
#include "teamInfo.h"

TableView::TableView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableView)
{
    ui->setupUi(this);
}

TableView::~TableView()
{
    delete ui;
}

void TableView::onLoadTable()
{
    QSqlTableModel* model = new QSqlTableModel(this);

    model->setTable("dbo.tbl_Record");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setSort(1, Qt::SortOrder::DescendingOrder);
    model->select();






    ui->tableView->setModel(model);
    qDebug() << model->lastError().text();
    qDebug() << "in tableview:";

}



void TableView::on_tableView_doubleClicked(const QModelIndex &index)
{
     QString value = ui->tableView->model()->data(index).toString();

     QSqlQuery qry;
     qry.prepare("SELECT * FROM [dbo].[tbl_Record] WHERE Wins='"+value+"' or Loses='"+value+"' or Team='"+value+"' ");

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
     qDebug() << team << " " << wins << " " << loses << " " << ties << " " << pts << " ";


}


