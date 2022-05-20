#ifndef SORTING_H
#define SORTING_H

#include <bits/stdc++.h>
#include <stdlib.h>
#include "generictask.h"
#include <iostream>
#include "EnumsType.h"

class sorting : public GenericTask
{
    Q_OBJECT
public:
    sorting();
    void merge(int a[], int p, int q, int r);

    int getListLen();

    void bubbleSort();
    void quickSort(int first = 0, int last = 0);
    void mergeSort(int first = 0, int last = 0);

    virtual void generateRandomArray();
    void printArray();

    virtual int getID() override {return this->ID;};
    virtual void setID(int id) override {this->ID = id;};
    virtual void setDif(EnumsType::Difficulty d) override {this->difficulty_ = d;};
    virtual void setType(EnumsType::PossibleType t)  override {this->type_ = t;};
public slots:
    virtual void calculate() override;


private:
    int ID;
    int * array;
    int size;
    int progress;
    EnumsType::Difficulty difficulty_;
    EnumsType::PossibleType type_;
    bool jump;
};

#endif // SORTING_H
