#include "sortingtask.h"

SortingTask::SortingTask()
{
    id = 0;
    i = 0;
}

SortingTask::~SortingTask()
{

}

int SortingTask::getID()
{
    return id;
}

void SortingTask::setID(int id)
{
    this->id = id;
}

void SortingTask::calculate()
{
    while(i<100)
    {
        emit updateProgressBar(i);
        i++;
    }
}
