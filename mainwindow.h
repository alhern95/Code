#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include "vector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mySqLiteDb;
    void conClose();
    bool conOpen();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_showColeges_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
