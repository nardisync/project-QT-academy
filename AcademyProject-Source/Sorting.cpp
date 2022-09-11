#include "Sorting.h"
#include <QDebug>
#include "unistd.h"

Sorting::Sorting()
{
    this->progress_ = 0;
    this->recursive_ = 0;
    this->jmpfactor_ = true;
    this->set_in_exec(false);
}

void Sorting::calculate()
{
    if(this->get_in_exec() == true){
        return;
    }
    this->set_in_exec(true);

    switch (this->type_) {
    case EnumsType::PossibleType::QuickSort:
        this->complexity_ = int((this->size_*this->size_)/100);
        quickSort();
        emit updateProgressBar(100);
        emit finished();
        break;
    case EnumsType::PossibleType::MergeSort:
        mergeSort();
        emit finished();
        break;
    case EnumsType::PossibleType::BubbleSort:
        bubbleSort();
        emit finished();
        break;
    default:
        break;
    }
}


void Sorting::quickSort(int first, int last)
{
    if (!jump_)
    {
        first = 0;
        last = this->size_;
        this->jump_ = true;
    }
    int i, j, pivot, temp;
       if(first<last){
          pivot=first;
          i=first;
          j=last;

          while(i<j){
             while(this->array_[i]<=this->array_[pivot]&&i<last)
                 {
                  i++;
                  this->progress_++;
                 }
             while(this->array_[j]>this->array_[pivot])
                {
                 j--;
                this->progress_++;
                }
            if(i<j){
                temp=this->array_[i];
                this->array_[i]=this->array_[j];
                this->array_[j]=temp;
                this->progress_++;
             }
          }

          temp=this->array_[pivot];
          this->array_[pivot]=this->array_[j];
          this->array_[j]=temp;
          quickSort(first,j-1);
          quickSort(j+1,last);

          this->progress_++;

          if (this->complexity_ < this->progress_ && this->recursive_ <= 100)
          {
              this->progress_ = 0;
              this->recursive_++;
              if (this->recursive_%5 == 0 && this->jmpfactor_ == false)
              {
                  this->jmpfactor_ = true;
                  emit updateProgressBar(this->recursive_);
              }
              else if (this->recursive_%5!=0)
              {
                  this->jmpfactor_ = false;
              }
          }
       }
}


void Sorting::mergeSort(int p, int r) {
  int q;


  if (!jump_)
  {
      r = this->size_;
      jump_ = true;
  }
  if (p < r) {
    q = (p+r)/2;
    mergeSort(p, q);
    mergeSort(q+1, r);
    merge(this->array_, p, q, r);
  }
}

void Sorting::bubbleSort()
{
    int i, j;
    for (i = 0; i < this->size_ - 1; i++) {
        for (j = 0; j < this->size_ - i - 1; j++)
            if (this->array_[j] > this->array_[j + 1])
                std::swap(this->array_[j], this->array_[j + 1]);

        this->progress_++;
        int signal = static_cast<int>((this->progress_*100)/(this->size_)+1);

        if (signal%5==0 && this->jmpfactor_ == false)
        {
            this->jmpfactor_ = true;
            emit updateProgressBar(signal);
        }
        else if (signal%5!=0)
        {
            this->jmpfactor_ = false;
        }
    }
}

void Sorting::generateRandomArray()
{
    int n = getListLen();
    this->size_ = n;
    this->array_ = new int[n];
    this->jump_ = false;

    int i;

    for (i = 0; i < this->size_; ++i)
    {
        this->array_[i] = std::rand()%this->size_;
    }
}

void Sorting::printArray()
{
    int i;
    for(i = 0; i < this->size_; ++i)
    {
        std::cout << this->array_[i] << " ";
    }
}

Sorting::~Sorting()
{
    delete [] array_;
}

void Sorting::merge(int a[], int p, int q, int r) {
  int i, j, k=0, b[this->size_];
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

  this->progress_++;
  int signal = static_cast<int>((this->progress_*100)/(this->size_));
  signal = signal+1;

  if (signal%5==0 && this->jmpfactor_ == false)
  {
      this->jmpfactor_ = true;
      emit updateProgressBar(signal);
  }
  else if (signal%5!=0)
  {
      this->jmpfactor_ = false;
  }
}

int Sorting::getListLen()
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
                    return 100000;
                case EnumsType::Difficulty::Medium:
                    return 250000;
                case EnumsType::Difficulty::Hard:
                    return 500000;
                default:
                    break;
        }
        case EnumsType::PossibleType::QuickSort:
            switch (this->difficulty_) {
                case EnumsType::Difficulty::Easy:
                    return 1000000;
                case EnumsType::Difficulty::Medium:
                    return 4500000;
                case EnumsType::Difficulty::Hard:
                    return 9000000;
                default:
                    break;
        }
        default:
            return 0;
    }
}
