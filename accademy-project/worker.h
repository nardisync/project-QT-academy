#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QProgressBar>
#include "MainWindow.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(Ui::MainWindow* ui);
    ~Worker();

    void handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty);
    void sendSignalCalculate();

signals:
    void launchTaskCalculate();

public slots:
    void slotUpdateProgressBar(int perc);

private:
    Ui::MainWindow* ui{nullptr};
    int progressThreadID;
    QMap<int, QString> progressBarThreadMap;


};

#endif // WORKER_H
