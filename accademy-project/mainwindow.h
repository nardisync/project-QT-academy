#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "EnumsType.h"
class Worker;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    EnumsType::PossibleApproch getApproch();
    EnumsType::PossibleType getType();
    EnumsType::Difficulty getDifficulty();

private slots:
    void on_pushButtonApply_clicked();
    void on_pushButtonAppendThread_clicked();
    void on_pushButtonAppendThreadStart_clicked();

private:
    Ui::MainWindow *ui;
    Worker *worker;

    void sendSignalCalculate();

};
#endif // MAINWINDOW_H
