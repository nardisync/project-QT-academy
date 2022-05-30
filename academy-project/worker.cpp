#include "Worker.h"
#include "ui_MainWindow.h"
#include "sorting.h"

// ====================== MAIN WINDOW ======================
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
// =========================================================



// ====================== GESTIONE DELLE SLOT ======================
void Worker::sendSignalCalculate()
{
    qDebug() << "Worker::sendSignalCalculate -> START";

    emit launchTaskCalculate();
    updateItemsAfterLaunchTask();

    qDebug() << "Worker::sendSignalCalculate -> STOP";
}
// ===============================================================



// ====================== GESTIONE DEL MODEL E DELLA VIEW ======================
void Worker::addNewItemOnModel(QString threadName, EnumsType::PossibleApproch threadApproch, EnumsType::PossibleType threadType, EnumsType::ThreadState threadState)
{
    qDebug() << "Worker::addNewItemOnModel -> START";
    qDebug() << "Worker::addNewItemOnModel -> ThreadName:    "  << threadName << "\n"
                "Worker::addNewItemOnModel -> ThreadApproch: "  << EnumsType::toString(threadApproch)   << "\n"
                "Worker::addNewItemOnModel -> ThreadType:    "  << EnumsType::toString(threadType)      << "\n"
                "Worker::addNewItemOnModel -> ThreadState:   "  << EnumsType::toString(threadState);

    QString threadInfo[4] = {threadName, EnumsType::toString(threadApproch),
                             EnumsType::toString(threadType), EnumsType::toString(threadState)};


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
            index = this->model->index(row, 3, QModelIndex());
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
        index = this->model->index(row, 3, QModelIndex());
        if(index.data() == EnumsType::toString(EnumsType::ThreadState::Started))
        {
            this->model->setData(index, EnumsType::toString(EnumsType::ThreadState::Working));
        }
    }

    qDebug() << "Worker::updateItemsAfterLaunchTask -> STOP";
}
// ==============================================================================



// ====================== GESTIONE DEGLI SLOT ======================
void Worker::slotUpdateProgressBar(int perc)
{
    //qDebug() << "Worker::slotUpdateProgressBar -> START";

    GenericTask * task = dynamic_cast<GenericTask*>(sender());
    QMap<int, QString>::iterator it = progressBarThreadMap.find(task->getID());

    QProgressBar* temp = ui->scrollAreaWidgetProgressBar->findChild<QProgressBar*>(it.value());
    temp->setValue(perc);
    if(perc == 100)
    {
        updateItemStateOnModel(it.value(), EnumsType::ThreadState::Completed);
    }

    //qDebug() << "Worker::slotUpdateProgressBar -> STOP";
}
// ================================================================



// ====================== GESTIONE DEI MESSAGGI IN INPUT ======================
void Worker::handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty)
{
    qDebug() << "Worker::handleMessage -> START";

    qDebug() << "Worker::handleMessage -> Approch:    " << EnumsType::toString(approch)     <<  "\n"
                "Worker::handleMessage -> Type:       " << EnumsType::toString(type)        <<  "\n"
                "Worker::handleMessage -> Difficulty: " << EnumsType::toString(difficulty)  <<  "\n";


    GenericTask * task{nullptr};

    if(approch == EnumsType::PossibleApproch::Sorting)
    {
        task = new sorting();
        task->setType(type);
        task->setDif(difficulty);
        task->generateRandomArray();

    }

    else if(approch == EnumsType::PossibleApproch::Merging)
    {
        if(type == EnumsType::PossibleType::NormalMerging)
        {
            //task = new NormalMergingTask();
        }
    }

    else if(approch == EnumsType::PossibleApproch::Problem)
    {
        if(type == EnumsType::PossibleType::NormalProblem)
        {
            //task = new NormalProblemTask();
        }
    }

    if(task != nullptr)
    {
        QString progressBarObjectUniqueName = addProgressBarToFrame(task);
        addNewItemOnModel(progressBarObjectUniqueName, approch, type, EnumsType::ThreadState::Started);
    }

    qDebug() << "Worker::handleMessage -> STOP";
}
// ============================================================================



// ====================== GESTIONE DELLA CREAZIONE DELLA PROGRESS BAR ======================
QString Worker::addProgressBarToFrame(GenericTask *task)
{
    qDebug() << "Worker::addProgressBarToFrame -> START";

    // Dichiarazione delle variabili
    QFrame*         progressBarHorFrame = new QFrame();
    QProgressBar*   progressBarObject   = new QProgressBar();
    QLabel*         progressBarLabel    = new QLabel();
    QHBoxLayout*    horizLayout         = new QHBoxLayout;
    QThread *       workerThread        = new QThread();

    // Gestione delle Connect e del Thread
    task->setID(progressThreadID);
    task->moveToThread(workerThread);
    QObject::connect(this, &Worker::launchTaskCalculate,    task, &GenericTask::calculate);
    QObject::connect(task, &GenericTask::updateProgressBar, this, &Worker::slotUpdateProgressBar);
    QObject::connect(task, &GenericTask::finished,          this, &Worker::deleteTask);

    // Gestione della Progress Bar
    QString progressBarObjectUniqueName   = "ProgressBar_ID_" + QString::number(progressThreadID);
    progressBarThreadMap.insert(progressThreadID, progressBarObjectUniqueName);
    progressBarObject->setObjectName(progressBarObjectUniqueName);
    progressBarObject->setValue(0);


    // Gestione della Label della Progress Bar
    QString progressBarLabelUniqueName   = "labelProgressBarID_" + QString::number(progressThreadID);
    progressBarLabel->setText(progressBarObjectUniqueName + ": ");
    progressBarLabel->setObjectName(progressBarLabelUniqueName);

    //Gestione del Frame della Progress Bar
    QString progressBarFrameUniqueName   = "FrameProgressBar_ID_" + QString::number(progressThreadID);
    progressBarHorFrame->setObjectName(progressBarFrameUniqueName);
    progressBarHorFrame->setLayout(horizLayout);
    progressBarHorFrame->layout()->addWidget(progressBarLabel);
    progressBarHorFrame->layout()->addWidget(progressBarObject);
    this->ui->scrollAreaWidgetProgressBar->layout()->addWidget(progressBarHorFrame);

    qDebug() << "Worker::addProgressBarToFrame -> Added new progressBarFrame:  " << progressBarFrameUniqueName;
    qDebug() << "Worker::addProgressBarToFrame -> Added new progressBarObject: " << progressBarObjectUniqueName;
    qDebug() << "Worker::addProgressBarToFrame -> Added new progressBarLabel:  " << progressBarLabelUniqueName;

    progressThreadID++;
    workerThread->start();

    qDebug() << "Worker::addProgressBarToFrame -> STOP";
    return progressBarObjectUniqueName;
}

void Worker::deleteTask()
{
    GenericTask * task = dynamic_cast<GenericTask*>(sender());
    qInfo() << "Worker::deleteTask -> Thread " << progressBarThreadMap.find(task->getID()).value() << " completed";

    delete task;
}

// ====================== GETTER ======================
QStandardItemModel* Worker::getModel()
{
    return model;
}
// ====================================================


