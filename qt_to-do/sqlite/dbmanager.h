#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSql>
#include <QSqlDatabase>

class DbManager
{
public:
    bool addTask(const QString& name, const QString& description);
    bool taskExists(const int id);
    bool deleteTask(const int id);
    QVector<QVector<QString>> getAll();
    static DbManager* getInstance();
private:
    QSqlDatabase m_db;
    static DbManager* s_instance;
    DbManager(const QString& path);
};

#endif // DBMANAGER_H
