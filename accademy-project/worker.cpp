#include "Worker.h"
#include "ui_mainwindow.h"

Worker::Worker(Ui::MainWindow* ui)
{
    this->ui = ui;
}

Worker::~Worker()
{

}

void Worker::handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty)
{
    qDebug() << "Worker::handleMessage -> START\n" ;

    qDebug() << "Worker::handleMessage -> Approch: " << (int)approch <<
                "\nWorker::handleMessage -> Type: " << (int)type <<
                "\nWorker::handleMessage -> Difficulty: " << (int)difficulty <<  "\n";

    //QThread * workerThread = new QThread();
    //GenericTask * task{nullptr};

    if(approch == EnumsType::PossibleApproch::Sorting)
    {
        qDebug() << "Worker::handleMessage -> Inside Sorting Approch" ;

        if(type == EnumsType::PossibleType::BubbleSort)
        {
            qDebug() << "Worker::handleMessage -> Inside BubbleSort Type" ;
            //task = new BubbleSortTask();

        }
        else if(type == EnumsType::PossibleType::MergeSort)
        {
            qDebug() << "Worker::handleMessage -> Inside MergeSort Type" ;
            //task = new MergeSortTask();
        }
        else if(type == EnumsType::PossibleType::QuickSort)
        {
            qDebug() << "Worker::handleMessage -> Inside QuickSort Type" ;
            //task = new QuickSortTask();
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

    /*
    if(task != nullptr)
    {
        task->setID(progressThreadID);
        task->moveToThread(workerThread);
        QObject::connect(this, launchTaskCalculate, task, &Task::calculate);
        QObject::connect(task, &Task::updateProgressBar, this, slotUpdateProgressBar);


        progressBarThreadMap->insert(progressThreadID, progressBarUniqueName);

        workerThread->start();
    }

    */

    QProgressBar *progressBar = new QProgressBar();
    QString progressBarUniqueName = "ProgressBar_ID_" + QString::number(progressThreadID);
    progressBar->setObjectName(progressBarUniqueName);
    progressThreadID += 1;
    progressBar->setValue(55);
    qDebug() << "Worker::handleMessage -> Added new progressBar: " << progressBarUniqueName;
    this->ui->progressBarFrame->layout()->addWidget(progressBar);

    qDebug() << "Worker::handleMessage -> STOP";
}

void Worker::sendSignalCalculate()
{
    qDebug() << "Worker::sendSignalCalculate -> START";
    emit launchTaskCalculate();
    qDebug() << "Worker::sendSignalCalculate -> STOP";
}

void Worker::slotUpdateProgressBar(int threadCallerID, int perc)
{
    qDebug() << "Worker::slotUpdateProgressBar -> START";
    QMap<int, QString>::iterator it = progressBarThreadMap->find(threadCallerID);
    (this->ui->progressBarFrameListView->findChild<QProgressBar *>(it.value()))->setValue(perc);
    qDebug() << "Worker::slotUpdateProgressBar -> STOP";
}


// connect(this, sendSignalCalculate, OGGETTOCREATOTRAMITEMARCO, SLOTCALCULATEIMPLEMENTATOMARCO)
