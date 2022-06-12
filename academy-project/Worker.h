#ifndef WORKER_H
#define WORKER_H

#include "GenericTask.h"
#include "GenericWorker.h"


class Worker : public GenericWorker
{
    Q_OBJECT
public:
    Worker();
    ~Worker();


    // Getter
    QStandardItemModel* getModel();


    // Setter
    // ....


    // Model and View Handler
    void addNewItemOnModel(QString threadInfo, EnumsType::PossibleApproch threadApproch, EnumsType::PossibleType threadType,
                           EnumsType::Difficulty threadDiff, EnumsType::ThreadState threadState);
    void updateItemsAfterLaunchTask();
    void updateItemStateOnModel(QString itemName, EnumsType::ThreadState newValue);
    QList<QString> returnCompletedTaskFromModel();


    // Signal and Slot Handler
    void sendSignalCalculate();

    // QMap Handlers
    void insertValueToProgressBarThreadMap(int taskID, QString progressBarObjectUniqueName);
    QString findValueInProgressBarThreadMap(int taskID);


    // Others
    GenericTask *handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty);

    void deleteTask();

signals:
    void launchTaskCalculate();

};

#endif // WORKER_H
