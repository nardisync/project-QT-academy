#ifndef GENERICTASK_H
#define GENERICTASK_H

#include <QObject>

class GenericTask : public QObject
{
    Q_OBJECT
public:
    virtual int  getID()        = 0;
    virtual void setID(int)     = 0;

public slots:
    virtual void calculate()    = 0;

signals:
    void updateProgressBar(int);

protected:
    int id;
};

#endif // GENERICTASK_H
