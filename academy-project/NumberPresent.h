#ifndef NUMBERPRESENT_H
#define NUMBERPRESENT_H
#include "stdlib.h"
#include "GenericTask.h"
#include "unistd.h"
#include <algorithm>
#include <iostream>
#include <QDebug>

class NumberPresent : public GenericTask
{
    Q_OBJECT
public:
    NumberPresent();

    int getListLen();
    void generateRandomArray() override;

    int getID() override {return this->ID_;};
    void setID(int id) override {this->ID_ = id;};
    void setDif(EnumsType::Difficulty d) override {this->difficulty_ = d;};
    void setType(EnumsType::PossibleType)  override {return;};

    virtual ~NumberPresent();

public slots:
    void calculate() override;

private:
    int ID_;
    EnumsType::Difficulty difficulty_;
    int * array_;
    int size_;
};

#endif // NUMBERPRESENT_H
