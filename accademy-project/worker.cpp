#include "Worker.h"
#include "ui_MainWindow.h"
#include "generictask.h"
#include "sorting.h"

Worker::Worker(Ui::MainWindow* ui)
{
    this->ui = ui;
    progressThreadID = 0;
}

Worker::~Worker()
{

}

void Worker::handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty)
{
    qDebug() << "Worker::handleMessage -> START\n";

    qDebug() << "Worker::handleMessage -> Approch: "        << (int)approch     <<
                "\nWorker::handleMessage -> Type: "         << (int)type        <<
                "\nWorker::handleMessage -> Difficulty: "   << (int)difficulty  <<  "\n";

    QThread * workerThread = new QThread();
    GenericTask * task{nullptr};

    if(approch == EnumsType::PossibleApproch::Sorting)
    {
        qDebug() << "Worker::handleMessage -> Inside Sorting Approch" ;

        if(type == EnumsType::PossibleType::BubbleSort)
        {
            qDebug() << "Worker::handleMessage -> Inside BubbleSort Type" ;
            task = new sorting();
            task->setType(type);
            task->setDif(difficulty);
            task->generateRandomArray();
        }
        else if(type == EnumsType::PossibleType::MergeSort)
        {
            qDebug() << "Worker::handleMessage -> Inside MergeSort Type" ;
            task = new sorting();
            task->setType(type);
            task->setDif(difficulty);
            task->generateRandomArray();
        }
        else if(type == EnumsType::PossibleType::QuickSort)
        {
            qDebug() << "Worker::handleMessage -> Inside QuickSort Type" ;
            task = new sorting();
            task->setType(type);
            task->setDif(difficulty);
            task->generateRandomArray();
        }
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
    }
}

void Worker::sendSignalCalculate()
{
    qDebug() << "Worker::sendSignalCalculate -> START";
    emit launchTaskCalculate();
}

void Worker::slotUpdateProgressBar(int perc)
{
    qDebug() << "Worker::slotUpdateProgressBar -> START";

    GenericTask * task = dynamic_cast<GenericTask*>(sender());
    QMap<int, QString>::iterator it = progressBarThreadMap.find(task->getID());
    QProgressBar* temp = ui->progressBarFrame->findChild<QProgressBar*>(it.value());
    temp->setValue(perc);
}


// connect(this, sendSignalCalculate, OGGETTOCREATOTRAMITEMARCO, SLOTCALCULATEIMPLEMENTATOMARCO)
