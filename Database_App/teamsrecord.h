#ifndef TEAMSRECORD_H
#define TEAMSRECORD_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class TeamsRecord;
}

class TeamsRecord : public QDialog
{
    Q_OBJECT

public:
    explicit TeamsRecord(QWidget *parent = 0);
    ~TeamsRecord();

signals:
    void transferData(QString, QString, QString, QString, QString);


public slots:
    void onLoadTable();


private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::TeamsRecord *ui;
};

#endif // TEAMSRECORD_H
