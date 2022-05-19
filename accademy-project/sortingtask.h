#ifndef SORTINGTASK_H
#define SORTINGTASK_H

#include "generictask.h"

class SortingTask : public GenericTask
{
    Q_OBJECT
public:
    SortingTask();
    ~SortingTask();

    int  getID();
    void setID(int);

public slots:
    void calculate();

private:
    int i;
};

#endif // SORTINGTASK_H
