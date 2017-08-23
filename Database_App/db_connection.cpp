#include "db_connection.h"

// Create a connection (i.e., an instance of QSqlDatabase) by calling one of the static addDatabase() functions
DB_Connection::DB_Connection(const QString& name): db(new QSqlDatabase(QSqlDatabase::addDatabase("QODBC")))
{
    db->setDatabaseName(name);
    db->open();

    if(db->open())
    {
        isConnected = true;
    }
}


DB_Connection::~DB_Connection()
{
    db->close();
    delete db;
    qDebug() << "Closing Db";
}

bool DB_Connection::Connect_To_DB()
{


    if(db->open())
    {
        qDebug() << "Connected";
        return true;

    }
    else
    {
        qDebug() << "Failed";
        return false;
    }
}

void DB_Connection::Close_Connection()
{
     db->close();
    isConnected = false;
}
