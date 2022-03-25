#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLine>
#include <QInputDialog>
#include <QString>
#include "sqlite\dbmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addTaskButton_clicked()
{
    bool ok;
    QString name, description;

    QString input1 = QInputDialog::getText(  this,  tr("Add Task"),
               tr("Enter task name"),
               QLineEdit::Normal, "", &ok );
    if( ok && !input1.isEmpty() )
    {
        name = input1;
    }

    QString input2 = QInputDialog::getText(  this,  tr("Add Task"),
               tr("Enter task description"),
               QLineEdit::Normal, "", &ok );
    if( ok )
    {
       description = input2;
    }

    DbManager *d = new DbManager("..\data\to-do_db.db");
    d->addTask(name, description);
}

