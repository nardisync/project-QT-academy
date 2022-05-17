#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>

class Worker
{
public:
    Worker();
    ~Worker();

    void handleMessage(QString approch, QString type, int difficulty);
};

#endif // WORKER_H
