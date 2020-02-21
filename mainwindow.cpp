#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    sqlitedb.setDatabaseName("/Users/tannercordero/ScrumDogs.db");

    if(!sqlitedb.open()) {

        QMessageBox::information(this, "Not Connected", "Database Not connected");
    }
    else {

        QMessageBox::information(this, "Connected", "Database is Connected Successfully");
    }
}
