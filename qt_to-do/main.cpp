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

    DbManager *d = DbManager::getInstance();

    MainWindow w;
    w.show();
    return a.exec();
}
