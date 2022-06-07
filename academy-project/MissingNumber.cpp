#include "MissingNumber.h"

MissingNumber::MissingNumber()
{
    std::srand( time(NULL) );
    this->set_in_exec(false);
}

void MissingNumber::calculate()
{
    if(this->get_in_exec() == true){
        return;
    }
    this->set_in_exec(true);

    std::vector<int> missing_numbers;
    std::sort(this->array_, this->array_+this->size_);

    int i, j;

    for (j = 1; j <= 50; j++)
    {
        for(i = 0; i < this->size_-1; ++i)
        {
            if ((this->array_[i+1]-this->array_[i])!=1 && this->array_[i] < this->size_)
            {
                missing_numbers.push_back(this->array_[i]+1);
            }

        }

        emit updateProgressBar(j*2);
    }
    emit finished();
}

int MissingNumber::getListLen()
{
    switch (this->difficulty_) {
    case EnumsType::Difficulty::Easy:
        return 1000000;
    case EnumsType::Difficulty::Medium:
        return 5000000;
    case EnumsType::Difficulty::Hard:
        return 10000000;
    default:
        break;
    }
    return 0;
}

void MissingNumber::generateRandomArray()
{
    this->size_ = getListLen();
    this->array_ = new int[this->size_];
    int i;
    int j = 0;
    for(i = 0; i < this->size_-1; ++i)
    {
        if (std::rand()%int(this->size_/3 )== 0)
        {
            j++;
        }
        this->array_[i] = j;
        j++;
    }
}
