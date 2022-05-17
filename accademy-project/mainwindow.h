#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString getApproch();
    QString getType();
    int getDifficulty();

private slots:
    void on_pushButtonApply_clicked();

private:
    Ui::MainWindow *ui;
    Worker *worker;

};
#endif // MAINWINDOW_H
