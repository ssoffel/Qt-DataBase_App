#include "teaminfo.h"
#include "ui_teaminfo.h"

TeamInfo::TeamInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamInfo)
{
    ui->setupUi(this);

    if(DB_Connection::instance().isConnected)
    {
        ui->label_status->setText("Connected");
    }
    else
    {
        ui->label_status->setText("Not Connected");
    }


}

TeamInfo::~TeamInfo()
{
    delete ui;
}

void TeamInfo::onTransferData(QString team, QString wins, QString loses, QString ties, QString pts)
{
    ui->lineEdit_Team->clear();
    ui->lineEdit_Wins->clear();
    ui->lineEdit_Loses->clear();
    ui->lineEdit_ties->clear();
    ui->lineEdit_Pts->clear();



    ui->lineEdit_Team->setText(team);
    ui->lineEdit_Wins->setText(wins);
    ui->lineEdit_Loses->setText(loses);
    ui->lineEdit_ties->setText(ties);
    ui->lineEdit_Pts->setText(pts);

}





void TeamInfo::on_pushButton_Save_clicked()
{
    //Create 4 String Variables to hold input data to save
    QString team, wins, loses, ties, pts;

    team = ui->lineEdit_Team->text();
    wins = ui->lineEdit_Wins->text();
    loses = ui->lineEdit_Loses->text();
    ties = ui->lineEdit_ties->text();
    pts = ui->lineEdit_Pts->text();

    qDebug() <<"Saving: " << team << " "<< wins << " " << loses << " " << ties << " " << pts << " " << "to database";

    //The QSqlQuery class provides a means of executing and manipulating SQL statements
    QSqlQuery qry;

    qry.prepare("INSERT INTO [dbo].[tbl_Record] ([Team],[Wins], [Loses], [Ties], [Pts]) VALUES ('"+team+"', '"+wins+"', '"+loses+"', '"+ties+"', '"+pts+"')");

    if(qry.exec())
    {
        QMessageBox::information(this, "Save", "Your data has been saved!");
    }
    else
    {
        QMessageBox::critical(this, "Error", qry.lastError().text());
    }
}

void TeamInfo::on_pushButton_Exit_clicked()
{

    ui->label_status->setText("Disconnecting...");
    qDebug() << "Closed";
    exit(0);
}



void TeamInfo::on_pushButton_Edit_clicked()
{
    QString team, wins, loses, ties, pts;

    team = ui->lineEdit_Team->text();
    wins = ui->lineEdit_Wins->text();
    loses = ui->lineEdit_Loses->text();
    ties = ui->lineEdit_ties->text();
    pts = ui->lineEdit_Pts->text();


    QSqlQuery qry;
    qry.prepare("UPDATE [dbo].[tbl_Record] SET Team ='"+team+"',Wins ='"+wins+"',Loses ='"+loses+"',Ties ='"+ties+"',Pts ='"+pts+"' WHERE Team='"+team+"'");

    if(qry.exec())
    {
       QMessageBox::information(this, "Updated", "Your data has been updated!");
    }
    else
    {
        QMessageBox::critical(this, "Error", qry.lastError().text());
    }





}

void TeamInfo::on_pushButton_Delete_clicked()
{
    QString team, wins, loses, ties, pts;

    team = ui->lineEdit_Team->text();
    wins = ui->lineEdit_Wins->text();
    loses = ui->lineEdit_Loses->text();
    ties = ui->lineEdit_ties->text();
    pts = ui->lineEdit_Pts->text();


    QSqlQuery qry;
    qry.prepare("DELETE FROM [dbo].[tbl_Record] WHERE Team ='"+team+"'");

    QMessageBox msgBox;
      msgBox.setText("Delete");
      msgBox.setInformativeText("Are you sure you want to Delete the record?");
      msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);

      int ret = msgBox.exec();
      switch (ret) {
         case QMessageBox::Yes:
             qry.exec();
             qDebug() << "Deleteing Record";
             break;
         case QMessageBox::Cancel:
             return;
             break;
         default:
             // should never be reached
             break;
       }
}

void TeamInfo::on_pushButton_LoadTable_clicked()
{


    TV = new TableView(this);

    connect(this, &TeamInfo::LoadTable, TV, &TableView::onLoadTable);

    emit LoadTable();

    TV->show();


}

void TeamInfo::on_pushButton_Load_Records_Table_clicked()
{
    TR = new TeamsRecord(this);
    connect(this, &TeamInfo::LoadRecordsTable, TR, &TeamsRecord::onLoadTable);
    connect(TR, &TeamsRecord::transferData, this, &TeamInfo::onTransferData);

    TR->show();

    emit LoadRecordsTable();
}

void TeamInfo::on_pushButton_List_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT Team FROM [dbo].[tbl_Record]");


    view = new QListView(this);

    view->setModel(model);
    view->setGeometry(300,300, 400, 300);
    ui->comboBox->setModel(model);
    view->show();



}

void TeamInfo::on_pushButton_clicked()
{
    view->close();
}

void TeamInfo::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString name = arg1;   //ui->comboBox->currentText();
    QSqlQuery qry;
    qry.prepare("Select * From [dbo].[tbl_Record] WHERE Team='"+name+"'");

    if(qry.exec())
    {
         while(qry.next())
            {
             ui->lineEdit_Team->setText(qry.value(0).toString());
             ui->lineEdit_Wins->setText(qry.value(1).toString());
             ui->lineEdit_Loses->setText(qry.value(2).toString());
             ui->lineEdit_ties->setText(qry.value(3).toString());
             ui->lineEdit_Pts->setText(qry.value(4).toString());
            }
    }

}

void TeamInfo::on_pushButton_2_clicked()
{

    ui->lineEdit_Team->setText(TV->team);
    ui->lineEdit_Wins->setText(TV->wins);
    ui->lineEdit_Loses->setText(TV->loses);
    ui->lineEdit_ties->setText(TV->ties);
    ui->lineEdit_Pts->setText(TV->pts);


    qDebug() << TV->team;
}



