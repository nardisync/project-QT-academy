#include "sorting.h"
#include <QDebug>
#include "unistd.h"

sorting::sorting()
{
    this->progress = 1;
    this->test = true;
    // steps:
    // sorting()
    // SetType, SetDifficulty
    // generateRandomArray
    // sortingAlgorithm
}

void sorting::calculate()
{
    if(in_exec_ == true){
        return;
    }
    in_exec_ = true;

    switch (this->type_) {
    case EnumsType::PossibleType::QuickSort:
        quickSort();
        emit finished();
        //this->progress = 0;
        break;
    case EnumsType::PossibleType::MergeSort:
        mergeSort();
        emit finished();
        //this->progress = 0;
        break;
    case EnumsType::PossibleType::BubbleSort:
        bubbleSort();
        emit finished();
        //this->progress = 0;
        break;
    default:
        break;
    }
}

void sorting::quickSort(int first, int last)
{
    if (!jump)
    {
        first = 0;
        last = this->size;
        this->jump = true;
    }
    int i, j, pivot, temp;
       if(first<last){
          pivot=first;
          i=first;
          j=last;

          while(i<j){
             while(this->array[i]<=this->array[pivot]&&i<last)
                i++;
             while(this->array[j]>this->array[pivot])
                j--;
             if(i<j){
                temp=this->array[i];
                this->array[i]=this->array[j];
                this->array[j]=temp;
             }
          }

          temp=this->array[pivot];
          this->array[pivot]=this->array[j];
          this->array[j]=temp;
          this->progress+=5;
          int signal = static_cast<int>((this->progress*100)/(this->size)+1);

          if (signal%5)
              emit updateProgressBar(signal);
          quickSort(first,j-1);
          quickSort(j+1,last);
       }
}


void sorting::mergeSort(int p, int r) {
  int q;
  this->progress+=5;
  int signal = static_cast<int>((this->progress*100)/(this->size)+1);

  if (signal%5)
      emit updateProgressBar(signal);

  if (!jump)
  {
      r = this->size;
      jump = true;
  }
  if (p < r) {
    q = (p+r)/2;
    mergeSort(p, q);
    mergeSort(q+1, r);
    merge(this->array, p, q, r);
  }
}

void sorting::bubbleSort()
{
    int i, j;
    for (i = 0; i < this->size - 1; i++) {
        for (j = 0; j < this->size - i - 1; j++)
            if (this->array[j] > this->array[j + 1])
                std::swap(this->array[j], this->array[j + 1]);

        this->progress++;
        int signal = static_cast<int>((this->progress*100)/(this->size)+1);

        if (signal%5==0 && this->test == false)
        {
            this->test = true;
            emit updateProgressBar(signal);
        }
        else if (signal%5!=0)
        {
            this->test = false;
        }
    }
}

void sorting::generateRandomArray()
{
    int n = getListLen();
    this->size = n;
    this->array = new int[n];
    this->jump = false;

    int i;

    for (i = 0; i < this->size; ++i)
    {
        this->array[i] = std::rand()%this->size;
    }
}

void sorting::printArray()
{
    int i;
    for(i = 0; i < this->size; ++i)
    {
        std::cout << this->array[i] << " ";
    }
}

void sorting::merge(int a[], int p, int q, int r) {
  int i, j, k=0, b[this->size];
  i = p;
  j = q+1;

  while (i<=q && j<=r) {
    if (a[i]<a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }
    k++;
  }
  while (i <= q) {
    b[k] = a[i];
    i++;
    k++;
  }
  while (j <= r) {
    b[k] = a[j];
    j++;
    k++;
  }
  for (k=p; k<=r; k++)
      a[k] = b[k-p];
}

int sorting::getListLen()
{

    switch (this->type_) {
        case EnumsType::PossibleType::BubbleSort:
            switch (this->difficulty_) {
                case EnumsType::Difficulty::Easy:
                    return 10000;
                case EnumsType::Difficulty::Medium:
                    return 50000;
                case EnumsType::Difficulty::Hard:
                    return 100000;
                default:
                    break;
        }
        case EnumsType::PossibleType::MergeSort:
            switch (this->difficulty_) {
                case EnumsType::Difficulty::Easy:
                    return 10000;
                case EnumsType::Difficulty::Medium:
                    return 50000;
                case EnumsType::Difficulty::Hard:
                    return 100000;
                default:
                    break;
        }
        case EnumsType::PossibleType::QuickSort:
            switch (this->difficulty_) {
                case EnumsType::Difficulty::Easy:
                    return 10000000;
                case EnumsType::Difficulty::Medium:
                    return 50000000;
                case EnumsType::Difficulty::Hard:
                    return 10000000;
                default:
                    break;
        }
        default:
            return 0;
    }
}
