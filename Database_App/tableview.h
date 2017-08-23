#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>



namespace Ui {
class TableView;
}

class TableView : public QDialog
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = 0);
    ~TableView();

    QString team = "Devils";
    QString wins, loses, ties, pts;




public slots:
    void onLoadTable();


private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::TableView *ui;




};

#endif // TABLEVIEW_H
