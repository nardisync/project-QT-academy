#include "Worker.h"
#include "ui_MainWindow.h"
#include "generictask.h"
#include "sorting.h"


Worker::Worker(Ui::MainWindow* ui)
{
    this->ui = ui;
    progressThreadID = 1;

    model = new QStandardItemModel(0, 4, this);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Thread Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Approch"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Status"));
}

Worker::~Worker()
{

}


// ====================== GESTIONE DELLE SLOT ======================
void Worker::sendSignalCalculate()
{
    qDebug() << "Worker::sendSignalCalculate -> START";

    emit launchTaskCalculate();
    updateItemsAfterLaunchTask();

    qDebug() << "Worker::sendSignalCalculate -> STOP";
}


// ====================== GESTIONE DEL MODEL E DELLA VIEW ======================
void Worker::addNewItemOnModel(QString threadName, EnumsType::PossibleApproch threadApproch, EnumsType::PossibleType threadType, EnumsType::ThreadState threadState)
{
    qDebug() << "Worker::addNewItemOnModel -> START";
    qDebug() << "Worker::addNewItemOnModel -> threadName: "         << threadName <<
                "\nWorker::addNewItemOnModel -> threadApproch: "    << EnumsType::toString(threadApproch)   <<
                "\nWorker::addNewItemOnModel -> threadType: "       << EnumsType::toString(threadType)      <<
                "\nWorker::addNewItemOnModel -> threadState: "      << EnumsType::toString(threadState);

    QString threadInfo[4] = {threadName, EnumsType::toString(threadApproch),
                             EnumsType::toString(threadType), EnumsType::toString(threadState)};

    this->model->insertRow(this->model->rowCount(QModelIndex()));

    int numberOfCol = this->model->columnCount(QModelIndex());
    int rowToInsert = this->model->rowCount(QModelIndex()) - 1;


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
    qDebug() << "Worker::updateItemStateOnModel -> itemName: " << itemName << "\n" <<
                "Worker::updateItemStateOnModel -> newValue: " << EnumsType::toString(newValue);

    QModelIndex index;
    for(int row = 0; row < this->model->rowCount(); row++)
    {
        index = this->model->index(row, 0, QModelIndex());
        if(index.data() == itemName)
        {
            index = this->model->index(row, 3, QModelIndex());
            this->model->setData(index, EnumsType::toString(newValue));
        }
    }

    qDebug() << "Worker::updateItemOnModel -> STOP";
}

void Worker::updateItemsAfterLaunchTask()
{
    qDebug() << "Worker::updateItemsAfterLaunchTask -> START";

    QModelIndex index;
    for(int row = 0; row < this->model->rowCount(); row++)
    {
        index = this->model->index(row, 3, QModelIndex());
        if(index.data() == EnumsType::toString(EnumsType::ThreadState::Started))
        {
            this->model->setData(index, EnumsType::toString(EnumsType::ThreadState::Working));
        }
    }

    qDebug() << "Worker::updateItemsAfterLaunchTask -> STOP";
}


// ====================== GESTIONE DEGLI SLOT ======================
void Worker::slotUpdateProgressBar(int perc)
{
    //qDebug() << "Worker::slotUpdateProgressBar -> START";

    GenericTask * task = dynamic_cast<GenericTask*>(sender());
    QMap<int, QString>::iterator it = progressBarThreadMap.find(task->getID());

    QProgressBar* temp = ui->progressBarFrame->findChild<QProgressBar*>(it.value());
    temp->setValue(perc);

    if(perc == 100)
    {
        updateItemStateOnModel(it.value(), EnumsType::ThreadState::Completed);
        //temp->~QProgressBar();
    }

    //qDebug() << "Worker::slotUpdateProgressBar -> STOP";
}


// ====================== GESTIONE DEI MESSAGGI IN INPUT ======================
void Worker::handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty)
{
    qDebug() << "Worker::handleMessage -> START";

    qDebug() << "Worker::handleMessage -> Approch: "    << EnumsType::toString(approch)     <<  "\n"
                "Worker::handleMessage -> Type: "       << EnumsType::toString(type)        <<  "\n"
                "Worker::handleMessage -> Difficulty: " << EnumsType::toString(difficulty)  <<  "\n";

    QThread * workerThread = new QThread();
    GenericTask * task{nullptr};

    if(approch == EnumsType::PossibleApproch::Sorting)
    {
        qDebug() << "Worker::handleMessage -> Inside Sorting Approch" ;
        task = new sorting();
        task->setType(type);
        task->setDif(difficulty);
        task->generateRandomArray();
    }

    else if(approch == EnumsType::PossibleApproch::Merging)
    {
        qDebug() << "Worker::handleMessage -> Inside Merging Approch" ;

        if(type == EnumsType::PossibleType::NormalMerging)
        {
            qDebug() << "Worker::handleMessage -> Inside NormalMerging Type" ;
            //task = new NormalMergingTask();
        }
    }

    else if(approch == EnumsType::PossibleApproch::Problem)
    {
        qDebug() << "Worker::handleMessage -> Inside Problem Approch" ;
        if(type == EnumsType::PossibleType::NormalProblem)
        {
            qDebug() << "Worker::handleMessage -> Inside NormalProblem Type" ;
            //task = new NormalProblemTask();
        }
    }


    if(task != nullptr)
    {
        // TO-DO
        // Tutto ciò potrebbe andare in un suo unico metodo, da vedere
        task->setID(progressThreadID);
        task->moveToThread(workerThread);
        QObject::connect(this, &Worker::launchTaskCalculate, task, &GenericTask::calculate);
        QObject::connect(task, &GenericTask::updateProgressBar, this, &Worker::slotUpdateProgressBar);

        QProgressBar* progressBar       = new QProgressBar();
        QString progressBarUniqueName   = "ProgressBar_ID_" + QString::number(progressThreadID);

        progressBarThreadMap.insert(progressThreadID, progressBarUniqueName);

        progressBar->setObjectName(progressBarUniqueName);
        progressThreadID++;

        qDebug() << "Worker::handleMessage -> Added new progressBar: " << progressBarUniqueName;
        progressBar->setValue(0);
        this->ui->progressBarFrame->layout()->addWidget(progressBar);
        workerThread->start();

        addNewItemOnModel(progressBarUniqueName, approch, type, EnumsType::ThreadState::Started);
    }

    qDebug() << "Worker::handleMessage -> STOP\n";
}


// ====================== GETTER ======================
QStandardItemModel* Worker::getModel()
{
    return model;
}
