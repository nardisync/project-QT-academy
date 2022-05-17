#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,   ui(new Ui::MainWindow),
        worker()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getApproch()
{
    return ui->comboBoxApproch->currentText();
}

QString MainWindow::getType()
{
    return ui->comboBoxType->currentText();
}

int MainWindow::getDifficulty()
{
    if(ui->radioButtonEasy->isChecked())
    {
        return 1;
    }
    else if(ui->radioButtonMedium->isChecked())
    {
        return 2;
    }
    else if(ui->radioButtonHard->isChecked())
    {
        return 3;
    }

    return 0;
}


void MainWindow::on_pushButtonApply_clicked()
{
    QString approch = this->getApproch();
    QString type = this->getType();
    int diff = this-> getDifficulty();

    this->worker->handleMessage(approch, type, diff);
}

