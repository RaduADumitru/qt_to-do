#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sqlite/dbmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // get all rows in to-do list from sql, store them in QVector of QString
    DbManager* dbManager = DbManager::getInstance();
    QVector<QVector<QString>> table = dbManager->getAll();

    QStringList headerNames = {"id", "name", "description", "status", "options"};


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

MainWindow::~MainWindow()
{
    delete ui;
}

