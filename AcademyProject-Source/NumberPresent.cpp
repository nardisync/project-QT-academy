#include "NumberPresent.h"

NumberPresent::NumberPresent()
{
    std::srand(time(NULL));
    this->set_in_exec(false);
}

void NumberPresent::calculate()
{
    if(this->get_in_exec() == true){
        return;
    }
    this->set_in_exec(true);

    int numberToFound;
    this->size_ = getListLen();
    this->array_ = new int[this->size_];
    int i, j;
    std::srand(time(NULL));
    for (i = 1; i <= 10; i++)
    {
        numberToFound = std::rand()%this->size_;
        generateRandomArray();
        for (j = 0; j < this->size_; j++)
        {
            if(this->array_[j] == numberToFound)
            {
                break;
            }
            std::srand(time(NULL));
        }
        emit updateProgressBar(i*10);
    }
    emit finished();
}

void NumberPresent::generateRandomArray()
{
    int i;
    for (i = 0; i < this->size_; ++i)
    {
        this->array_[i] = std::rand()%(this->size_);
    }
}

NumberPresent::~NumberPresent()
{
    delete [] array_;
}

int NumberPresent::getListLen()
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

