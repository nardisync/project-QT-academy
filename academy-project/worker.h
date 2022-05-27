#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QProgressBar>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QMessageBox>
#include "MainWindow.h"
#include "generictask.h"


class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(Ui::MainWindow* ui);
    ~Worker();


    // Getter
    QStandardItemModel* getModel();


    // Setter
    // ....


    // Model and View Handler
    void addNewItemOnModel(QString threadInfo, EnumsType::PossibleApproch threadApproch, EnumsType::PossibleType threadType, EnumsType::ThreadState threadState);
    void updateItemsAfterLaunchTask();
    void updateItemStateOnModel(QString itemName, EnumsType::ThreadState newValue);


    // Signal and Slot Handler
    void sendSignalCalculate();


    // Others
    QString addProgressBarToFrame(GenericTask* task);
    void handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty);

    void deleteTask();

signals:
    void launchTaskCalculate();


public slots:
    void slotUpdateProgressBar(int perc);


private:
    Ui::MainWindow* ui{nullptr};
    QStandardItemModel *model;
    QMap<int, QString> progressBarThreadMap;
    int progressThreadID;
};

#endif // WORKER_H
