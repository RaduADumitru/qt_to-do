#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSql>
#include <QSqlDatabase>

class DbManager
{
public:
    DbManager(const QString& path);
    bool addTask(const QString& name, const QString& description);
    bool taskExists(const int id);
    bool deleteTask(const int id);
    QVector<QVector<QString>> getAll();
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
