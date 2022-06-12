#include "Worker.h"
#include "Sorting.h"
#include "MissingNumber.h"
#include "NumberPresent.h"


// ====================== MAIN WINDOW =========================================
Worker::Worker()
{
    qDebug() << "Worker::Worker Constructor -> START";
    progressThreadID = 1;

    model = new QStandardItemModel(0, 5, this);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Thread Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Approch"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Difficulty"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Status"));
    qDebug() << "Worker::Worker Constructor -> STOP";
}

Worker::~Worker()
{

}
// ============================================================================



// ====================== GESTIONE DELLE SLOT =================================
void Worker::sendSignalCalculate()
{
    qDebug() << "Worker::sendSignalCalculate -> START";

    emit launchTaskCalculate();
    updateItemsAfterLaunchTask();

    qDebug() << "Worker::sendSignalCalculate -> STOP";
}
// ============================================================================


// ============================ GESTIONE DELLA QMAP ============================
void Worker::insertValueToProgressBarThreadMap(int taskID, QString progressBarObjectUniqueName)
{
    progressBarThreadMap.insert(taskID, progressBarObjectUniqueName);
}

QString Worker::findValueInProgressBarThreadMap(int taskID)
{
    qDebug() << "Worker::findValueInProgressBarThreadMap -> START";

    QMap<int, QString>::iterator it = progressBarThreadMap.find(taskID);
    QString value = it.value();
    qDebug() << "Worker::findValueInProgressBarThreadMap -> Finded Value: " << value;
    qDebug() << "Worker::findValueInProgressBarThreadMap -> STOP";
    return value;
}
// =============================================================================


// ====================== GESTIONE DEL MODEL E DELLA VIEW ======================
void Worker::addNewItemOnModel(QString threadName, EnumsType::PossibleApproch threadApproch,
                               EnumsType::PossibleType threadType, EnumsType::Difficulty threadDiff,
                               EnumsType::ThreadState threadState)
{
    qDebug() << "Worker::addNewItemOnModel -> START";
    qDebug() << "Worker::addNewItemOnModel -> ThreadName:    "  << threadName << "\n"
                "Worker::addNewItemOnModel -> ThreadApproch: "  << EnumsType::toString(threadApproch)   << "\n"
                "Worker::addNewItemOnModel -> ThreadType:    "  << EnumsType::toString(threadType)      << "\n"
                "Worker::addNewItemOnModel -> ThreadDiff:    "  << EnumsType::toString(threadDiff)      << "\n"
                "Worker::addNewItemOnModel -> ThreadState:   "  << EnumsType::toString(threadState);

    QString threadInfo[5] = {threadName, EnumsType::toString(threadApproch), EnumsType::toString(threadType),
                             EnumsType::toString(threadDiff), EnumsType::toString(threadState)};


    this->model->insertRow(0);

    int numberOfCol = this->model->columnCount(QModelIndex());
    int rowToInsert = 0;


    for(int position = 0; position < numberOfCol; position++)
    {
        QModelIndex index = this->model->index(rowToInsert, position, QModelIndex());
        this->model->setData(index, threadInfo[position]);
    }

    qDebug() << "Worker::addNewItemOnModel -> STOP";

}

void Worker::updateItemStateOnModel(QString itemName, EnumsType::ThreadState newValue)
{
    qDebug() << "Worker::updateItemStateOnModel -> START";
    qDebug() << "Worker::updateItemStateOnModel -> ItemName: "  << itemName << "\n"
                "Worker::updateItemStateOnModel -> NewValue: "  << EnumsType::toString(newValue);

    QModelIndex index;
    for(int row = 0; row < this->model->rowCount(); row++)
    {
        index = this->model->index(row, 0, QModelIndex());
        if(index.data() == itemName)
        {
            index = this->model->index(row, 4, QModelIndex());
            this->model->setData(index, EnumsType::toString(newValue));
        }
    }

    qDebug() << "Worker::updateItemStateOnModel -> STOP";
}

void Worker::updateItemsAfterLaunchTask()
{
    qDebug() << "Worker::updateItemsAfterLaunchTask -> START";

    QModelIndex index;
    for(int row = 0; row < this->model->rowCount(); row++)
    {
        index = this->model->index(row, 4, QModelIndex());
        if(index.data() == EnumsType::toString(EnumsType::ThreadState::Started))
        {
            this->model->setData(index, EnumsType::toString(EnumsType::ThreadState::Working));
        }
    }

    qDebug() << "Worker::updateItemsAfterLaunchTask -> STOP";
}

QList<QString> Worker::returnCompletedTaskFromModel()
{
    qDebug() << "Worker::returnCompletedTaskFromModel -> START";

    QList<QString>  completedTasks = {};
    QModelIndex     index;

    for(int row = 0; row < this->model->rowCount(); row++)
    {
        index = this->model->index(row, 4, QModelIndex());
        if(index.data() == EnumsType::toString(EnumsType::ThreadState::Completed))
        {
            QModelIndex stringIndex;
            stringIndex = this->model->index(row, 0, QModelIndex());
            completedTasks.append(stringIndex.data().toString());
        }
    }
    qDebug() << "Worker::returnCompletedTaskFromModel -> completedTasks result: " << completedTasks ;
    qDebug() << "Worker::returnCompletedTaskFromModel -> STOP";

    return completedTasks;
}

// =============================================================================


// ====================== GESTIONE DEI MESSAGGI IN INPUT =======================
GenericTask* Worker::handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty)
{
    qDebug() << "Worker::handleMessage -> START";

    qDebug() << "Worker::handleMessage -> Approch:    " << EnumsType::toString(approch)     <<  "\n"
                "Worker::handleMessage -> Type:       " << EnumsType::toString(type)        <<  "\n"
                "Worker::handleMessage -> Difficulty: " << EnumsType::toString(difficulty)  <<  "\n";

    GenericTask * task{nullptr};

    if(approch == EnumsType::PossibleApproch::Sorting)
    {
        task = new Sorting();
        task->setType(type);
        task->setDif(difficulty);
        task->generateRandomArray();

    }

    else if(approch == EnumsType::PossibleApproch::Present)
    {
        if(type == EnumsType::PossibleType::NumberPresent)
        {
            task = new NumberPresent();
            task->setDif(difficulty);
        }
    }

    else if(approch == EnumsType::PossibleApproch::Problem)
    {
        if(type == EnumsType::PossibleType::MissingNumber)
        {
            task = new MissingNumber();
            task->setDif(difficulty);
            task->generateRandomArray();
        }
    }

    if(task != nullptr)
    {
        // Creazione del Thread che gestirà la Task
        QThread     * workerThread  = new QThread();

        // Gestione delle Connect e del Thread
        task->setID(progressThreadID);
        task->moveToThread(workerThread);
        QObject::connect(this, &Worker::launchTaskCalculate,    task, &GenericTask::calculate);
        QObject::connect(task, &GenericTask::finished,          this, &Worker::deleteTask);
        progressThreadID++;
        workerThread->start();

        return task;
    }

    return nullptr;

    qDebug() << "Worker::handleMessage -> STOP";
}
// =============================================================================


void Worker::deleteTask()
{
    qDebug() << "Worker::deleteTask -> START";
    GenericTask * task = dynamic_cast<GenericTask*>(sender());
    qInfo() << "Worker::deleteTask -> Thread " << progressBarThreadMap.find(task->getID()).value() << " completed";

    delete task;
    qDebug() << "Worker::deleteTask -> STOP";
}

// ====================== GETTER ===============================================
QStandardItemModel* Worker::getModel()
{
    qDebug() << "Worker::getModel -> START";
    return model;
}
// =============================================================================


