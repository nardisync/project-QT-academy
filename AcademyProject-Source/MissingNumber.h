#ifndef MISSINGNUMBER_H
#define MISSINGNUMBER_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "GenericTask.h"

class MissingNumber : public GenericTask
{
    Q_OBJECT
public:
    MissingNumber();

    int getListLen();
    void generateRandomArray() override;

    int getID() override {return this->ID_;};
    void setID(int id) override {this->ID_ = id;};
    void setDif(EnumsType::Difficulty d) override {this->difficulty_ = d;};
    void setType(EnumsType::PossibleType)  override {return;};

public slots:
    void calculate() override;

private:
    int * array_;
    int size_;
    int ID_;
    EnumsType::Difficulty difficulty_;
    std::vector<int> missingNumbers_;
};

#endif // MISSINGNUMBER_H
