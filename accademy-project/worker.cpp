#include "worker.h"

Worker::Worker()
{

}

Worker::~Worker()
{

}

void Worker::handleMessage(QString approch, QString type, int difficulty)
{
    qDebug() << "handleMessage -> START" ;

    qDebug() << "Approch: " << approch <<
                "\nType: " << type <<
                "Difficulty: " << difficulty << "\n";

    qDebug() << "handleMessage -> STOP" ;
}
