#ifndef GENERICWORKER_H
#define GENERICWORKER_H


#include <QThread>
#include <QObject>
#include <QDebug>
#include <QProgressBar>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QMessageBox>
#include "EnumsType.h"
#include "GenericTask.h"

class GenericWorker : public QObject
{
    Q_OBJECT
public:

    // Getter
    virtual QStandardItemModel* getModel() = 0;

    // Setter
    // ...

    // Model and View Handler
    virtual void addNewItemOnModel(QString threadInfo, EnumsType::PossibleApproch threadApproch, EnumsType::PossibleType threadType,
                           EnumsType::Difficulty threadDiff, EnumsType::ThreadState threadState) = 0;
    virtual void updateItemsAfterLaunchTask() = 0;
    virtual void updateItemStateOnModel(QString itemName, EnumsType::ThreadState newValue) = 0;


    // Signal and Slot Handler
    virtual void sendSignalCalculate() = 0;

    // QMap Handlers
    virtual void insertValueToProgressBarThreadMap(int taskID, QString progressBarObjectUniqueName) = 0;
    virtual QString findValueInProgressBarThreadMap(int taskID) = 0;


    // Others
    virtual GenericTask * handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty) = 0;
    virtual void deleteTask() = 0;

signals:
    void launchTaskCalculate();

protected:
    QStandardItemModel *model;
    QMap<int, QString> progressBarThreadMap;
    int progressThreadID;
};


#endif // GENERICWORKER_H
