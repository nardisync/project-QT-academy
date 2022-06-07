#ifndef ENUMSTYPE_H
#define ENUMSTYPE_H

#include <QString>

class EnumsType
{
public:

    // =======================
    // Gestione dell'approccio
    // =======================
    enum class PossibleApproch
    {
        Sorting = 0,
        Present = 1,
        Problem = 2,
        None = 69
    };


    // =====================================
    // Gestione delle tipologie di approccio
    // =====================================
    enum class PossibleType
    {
        // SortingType
        BubbleSort = 0,
        QuickSort = 1,
        MergeSort =2,

        //MergingType
        NumberPresent = 3,

        //ProblemType
        MissingNumber = 6,

        //Error
        None = 69
    };


    // =========================
    // Gestione della difficoltà
    // =========================
    enum class Difficulty
    {
        Easy = 0,
        Medium = 1,
        Hard = 2,
        None = 69
    };

    enum class ThreadState
    {
        Completed = 0,
        Working = 1,
        Started = 2,
        Pending = 3,
        None = 69
    };


    // =================== GESTIONE DEL ENUM TO STRING DI APPROCH ===================
    static QString toString(EnumsType::PossibleApproch enumApproch)
    {
        QString enumToString;
        switch(enumApproch) {
            case EnumsType::PossibleApproch::Sorting: enumToString = "Sorting"; break;
            case EnumsType::PossibleApproch::Present: enumToString = "Present"; break;
            case EnumsType::PossibleApproch::Problem: enumToString = "Problem"; break;
            case EnumsType::PossibleApproch::None: enumToString = "None"; break;
            default: printf("Invalid Enum Type"); enumToString = "Error";
        }
        return enumToString;
    }
    // ==============================================================================



    // =================== GESTIONE DEL ENUM TO STRING DI TYPE ===================
    static QString toString(EnumsType::PossibleType enumType)
    {
        QString enumToString;
        switch(enumType) {
            case EnumsType::PossibleType::BubbleSort: enumToString = "BubbleSort Algorithm"; break;
            case EnumsType::PossibleType::QuickSort: enumToString = "QuickSort Algorithm"; break;
            case EnumsType::PossibleType::MergeSort: enumToString = "MergeSort Algorithm"; break;
            case EnumsType::PossibleType::NumberPresent: enumToString = "Number is present Algorithm"; break;
            case EnumsType::PossibleType::MissingNumber: enumToString = "Missing Number Algorithm"; break;
            case EnumsType::PossibleType::None: enumToString = "None"; break;
            default: printf("Invalid Enum Type"); enumToString = "Error";
        }
        return enumToString;
    }
    // ==========================================================================



    // =================== GESTIONE DEL ENUM TO STRING DI DIFFICULTY ===================
    static QString toString(EnumsType::Difficulty enumDiff)
    {
        QString enumToString;
        switch(enumDiff) {
            case EnumsType::Difficulty::Easy: enumToString = "Easy"; break;
            case EnumsType::Difficulty::Medium: enumToString = "Medium"; break;
            case EnumsType::Difficulty::Hard: enumToString = "Hard"; break;
            case EnumsType::Difficulty::None: enumToString = "None"; break;
            default: printf("Invalid Enum Type"); enumToString = "Error";
        }
        return enumToString;
    }
    // ==================================================================================



    // =================== GESTIONE DEL ENUM TO STRING DI THREAD STATE ===================
    static QString toString(EnumsType::ThreadState enumThreadState)
    {
        QString enumToString;
        switch(enumThreadState) {
            case EnumsType::ThreadState::Completed: enumToString = "Completed"; break;
            case EnumsType::ThreadState::Working: enumToString = "Working"; break;
            case EnumsType::ThreadState::Started: enumToString = "Started"; break;
            case EnumsType::ThreadState::Pending: enumToString = "Pending"; break;
            case EnumsType::ThreadState::None: enumToString = "None"; break;
            default: printf("Invalid Enum Type"); enumToString = "Error";
        }
        return enumToString;
    }
    // ====================================================================================


};
#endif // ENUMSTYPE_H
