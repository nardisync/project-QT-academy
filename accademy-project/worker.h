#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include "EnumsType.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker();
    ~Worker();

    void handleMessage(EnumsType::PossibleApproch approch, EnumsType::PossibleType type, EnumsType::Difficulty difficulty);
    void sendSignalCalculate();

signals:
    void launchTaskCalculate();



};

#endif // WORKER_H
