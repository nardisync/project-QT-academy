#ifndef GENERICTASK_H
#define GENERICTASK_H

#include <QObject>
#include "EnumsType.h"

class GenericTask : public QObject
{
    Q_OBJECT
public:
    // Getter
    inline bool get_in_exec() {return this->in_exec;};
    virtual int  getID()        = 0;

    // Setter
    inline void set_in_exec(bool exec_) {this->in_exec = exec_;};
    virtual void setID(int)     = 0;

    virtual void setDif(EnumsType::Difficulty d) = 0;
    virtual void setType(EnumsType::PossibleType t) = 0;
    virtual void generateRandomArray() = 0;

public slots:
    virtual void calculate()    = 0;

signals:
    void updateProgressBar(int);
    void finished();

protected:
    int id;

private:
    bool in_exec;
};

#endif // GENERICTASK_H
