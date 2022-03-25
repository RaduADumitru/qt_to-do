#include "mainwindow.h"


#include "sqlite\dbmanager.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "qt_to-do_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    //sqlite

<<<<<<< HEAD
    DbManager *d = new DbManager("..\data\to-do_db.db");
=======
    DbManager *d = DbManager::getInstance();
>>>>>>> b193b3b43b63138eaad8d37548ca4f5045c9f572

    MainWindow w;
    w.show();
    return a.exec();
}
