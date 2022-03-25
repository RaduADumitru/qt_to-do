#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLine>
#include <QInputDialog>
#include <QString>
#include "sqlite\dbmanager.h"

<<<<<<< HEAD
#include "sqlite/dbmanager.h"

void MainWindow::Generate()
{
    QStringList headerNames = {"id", "name", "description", "status", "options"};
    DbManager* dbManager = DbManager::getInstance();
    QVector<QVector<QString>> table = dbManager->getAll();
    ui->tableWidget->setColumnCount(headerNames.size());
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(headerNames);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int row = 0; row < table.size(); row++) {
        ui->tableWidget->insertRow(row);
        for (int col = 0; col < headerNames.size()-1; col++) {
            ui->tableWidget-> setCellWidget(row, col, new QLabel);
            QLabel *cellLabel = qobject_cast<QLabel *>(ui->
                                                       tableWidget->
                                                       cellWidget(row, col));

            cellLabel->setText(table[row][col]);
            cellLabel->setAlignment(Qt::AlignHCenter);
        }
    }
}
=======
#include <QCheckBox>

#include "sqlite/dbmanager.h"
>>>>>>> b193b3b43b63138eaad8d37548ca4f5045c9f572

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // get all rows in to-do list from sql, store them in QVector of QString
<<<<<<< HEAD
    Generate();

=======
    DbManager* dbManager = DbManager::getInstance();
    QVector<QVector<QString>> table = dbManager->getAll();

    QStringList headerNames = {"id", "name", "description", "status", "options"};


    ui->tableWidget->setColumnCount(headerNames.size());
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(headerNames);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int row = 0; row < table.size(); row++) {
        ui->tableWidget->insertRow(row);
        int col;
        for (col = 0; col < headerNames.size()-2; col++) {
            ui->tableWidget-> setCellWidget(row, col, new QLabel);
            QLabel *cellLabel = qobject_cast<QLabel *>(ui->
                                                       tableWidget->
                                                       cellWidget(row, col));

            cellLabel->setText(table[row][col]);
            cellLabel->setAlignment(Qt::AlignHCenter);
        }

        ui->tableWidget->setCellWidget(row, col, new QCheckBox);
        QCheckBox *checkBox = qobject_cast<QCheckBox *>(ui->
                                                        tableWidget->
                                                        cellWidget(row, col));

        if (table[row][col] == "0")
            checkBox->setCheckState(Qt::Unchecked);
        else
            checkBox->setCheckState(Qt::Checked);
    }
>>>>>>> b193b3b43b63138eaad8d37548ca4f5045c9f572
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

    DbManager *d = DbManager::getInstance();
    d->addTask(name, description);
<<<<<<< HEAD
    Generate();
=======
>>>>>>> b193b3b43b63138eaad8d37548ca4f5045c9f572
}

