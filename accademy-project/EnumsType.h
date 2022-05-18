#ifndef ENUMSTYPE_H
#define ENUMSTYPE_H

#endif // ENUMSTYPE_H

class EnumsType
{
public:
    // =======================
    // Gestione dell'approccio
    // =======================

    enum class PossibleApproch
    {
        Sorting = 0,
        Merging = 1,
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
        NormalMerging = 3,

        //ProblemType
        NormalProblem = 6,

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

};
