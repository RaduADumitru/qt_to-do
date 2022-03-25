#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLine>
#include <QInputDialog>
#include <QString>
#include <QCheckBox>
#include "sqlite\dbmanager.h"

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
    int row = 0, col = 0;
    for (row = 0; row < table.size(); row++) {
        ui->tableWidget->insertRow(row);

        for (col = 0; col < headerNames.size()-1; col++) {
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
        col++;
        ui->tableWidget->setCellWidget(row, col, new QPushButton("Delete"));
        QPushButton *pushButton = qobject_cast<QPushButton *>(ui->tableWidget->cellWidget(row, col));

    }
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
    Generate();
}

