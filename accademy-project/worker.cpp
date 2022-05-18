#include "Worker.h"

Worker::Worker()
{

}

Worker::~Worker()
{

}

void Worker::handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty)
{
    qDebug() << "handleMessage -> START\n" ;

    qDebug() << "Approch: " << (int)approch <<
                "\nType: " << (int)type <<
                "\nDifficulty: " << (int)difficulty <<  "\n";


    if(approch == EnumsType::PossibleApproch::Sorting)
    {
        qDebug() << "Inside Sorting Approch" ;

        if(type == EnumsType::PossibleType::BubbleSort)
        {
            qDebug() << "Inside BubbleSort Type" ;
        }
        else if(type == EnumsType::PossibleType::MergeSort)
        {
            qDebug() << "Inside MergeSort Type" ;
        }
        else if(type == EnumsType::PossibleType::QuickSort)
        {
            qDebug() << "Inside QuickSort Type" ;
        }
    }

    else if(approch == EnumsType::PossibleApproch::Merging)
    {
        qDebug() << "Inside Merging Approch" ;

        if(type == EnumsType::PossibleType::NormalMerging)
        {
            qDebug() << "Inside NormalMerging Type" ;
        }
    }

    else if(approch == EnumsType::PossibleApproch::Problem)
    {
        qDebug() << "Inside Problem Approch" ;
        if(type == EnumsType::PossibleType::NormalProblem)
        {
            qDebug() << "Inside NormalProblem Type" ;
        }
    }


    qDebug() << "handleMessage -> STOP";
}

void Worker::sendSignalCalculate()
{
    emit launchTaskCalculate();
}


// connect(this, sendSignalCalculate, OGGETTOCREATOTRAMITEMARCO, SLOTCALCULATEIMPLEMENTATOMARCO)
