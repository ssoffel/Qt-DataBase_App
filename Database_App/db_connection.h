#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>


const QString DATABASE_FILENAME = "sql_Server_dsn";

class DB_Connection
{
public:
    static DB_Connection& instance()
    {
        static DB_Connection singleton;
        return singleton;
    }

    ~DB_Connection();
    bool Connect_To_DB();
    void Close_Connection();

    bool isConnected;

private:
    DB_Connection(const QString& name = DATABASE_FILENAME);

    DB_Connection& operator=(const DB_Connection& rhs);

    QSqlDatabase *db;





};

#endif // DB_CONNECTION_H
