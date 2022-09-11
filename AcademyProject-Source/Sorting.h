#ifndef Sorting_H
#define Sorting_H

//#include <bits/stdc++.h>
#include <stdlib.h>
#include "GenericTask.h"
#include <iostream>
#include "EnumsType.h"

class Sorting : public GenericTask
{
    Q_OBJECT
public:
    Sorting();
    void merge(int a[], int p, int q, int r);

    int getListLen();

    void bubbleSort();
    void quickSort(int first = 0, int last = 0);
    void mergeSort(int first = 0, int last = 0);

    void generateRandomArray() override;
    void printArray();

    int getID() override {return this->ID_;}
    void setID(int id) override {this->ID_ = id;}
    void setDif(EnumsType::Difficulty d) override {this->difficulty_ = d;}
    void setType(EnumsType::PossibleType t)  override {this->type_ = t;}

    virtual ~Sorting();
public slots:
    void calculate() override;


private:
    int ID_;
    int * array_;
    int size_;
    int progress_;
    int recursive_;
    int complexity_;
    EnumsType::Difficulty difficulty_;
    EnumsType::PossibleType type_;
    bool jump_;
    bool jmpfactor_;
};

#endif // Sorting_H
