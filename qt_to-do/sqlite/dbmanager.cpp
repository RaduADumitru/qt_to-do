#include "dbmanager.h"
#include "qdebug.h"
#include <QString>
#include <QSql>

DbManager::DbManager(const QString& path)
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);

   if (!m_db.open())
   {
      qDebug() << "Error: connection with database failed";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

bool DbManager::addTask(const QString& name, const QString& description)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO Tasks (name, description) VALUES (:name, :description)");
   query.bindValue(":name", name);
   query.bindValue(":description", description);
   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addTask error:"
                 << query.lastError();
   }

   return success;
}

bool DbManager::taskExists(const int id){
    QSqlQuery query;
    query.prepare("SELECT * FROM Tasks WHERE id = (:id)");
    query.bindValue(":id", id);

    if (query.exec())
    {
       if (query.next())
       {
          //it exists
           return 1;
       }
    }
    return 0;
}
QVector<QVector<QString>> DbManager::getAll() {
    QSqlQuery query("SELECT id, name, description, isDone FROM Tasks");
    QVector<QVector<QString>> v;
    int row = 0;
    while (query.next())
    {
        v.push_back(QVector<QString>(4));
       for(int col = 0; col < 4; col++){
           v[row][col] = query.value(col).toString();
       }
       row++;
    }
    return v;
}
bool DbManager::deleteTask(const int id){
    bool success = false;
    if (taskExists(id))
    {
       QSqlQuery query;
       query.prepare("DELETE FROM Tasks WHERE id = (:id)");
       query.bindValue(":id", id);
       success = query.exec();

       if(!success)
       {
           qDebug() << "removeTask error:"
                    << query.lastError();
       }
    }

    return success;
}
