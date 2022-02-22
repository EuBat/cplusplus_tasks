#pragma once
#include "matrix.h"

template <typename T>
class Sort
{
    Sort();
    ~Sort();
    public:
    static T Partition(T* PtrToArray, size_t RangeBegin, size_t RangeEnd)
    {
//        std::cout << "Before partition\n";
        for(int k = RangeBegin; k < RangeEnd; k++)
        {
//            std::cout << "  "<< *(PtrToArray+k);
        }
//        std::cout << "> \n" << std::endl;
//        std::cout << "Range Begin " << RangeBegin << std::endl;
//        std::cout << "Range End   " << RangeEnd   << std::endl;

        T BaseElement {*(PtrToArray+RangeEnd-1)};
//        std::cout << "> Base Element = " << *(PtrToArray+RangeEnd-1) << std::endl;
        T TempElement {0};
        size_t i {RangeBegin};
        for(int j = RangeBegin; j < RangeEnd; j++)
        {
//            std::cout << "> j =     " << *(PtrToArray+j) << "\n";
            if(*(PtrToArray+j) <= BaseElement)
            {
                TempElement = *(PtrToArray + i);
                *(PtrToArray + i)  = *(PtrToArray + j) ;
                *(PtrToArray + j)  = TempElement;
                i++;
//                std::cout << "x> i =     " << i << "     " <<  *(PtrToArray+i) << "\n";
            }
        }
//        std::cout << "> after partition\n";
        for(int k = RangeBegin; k<RangeEnd; k++)
        {
//            std::cout << "  "<< *(PtrToArray+k);
        }
//        std::cout << "> \n" << std::endl;
        return i;
    }

    static void QuickSort(T* PtrToArray, size_t RangeBegin, size_t RangeEnd)
    {
        if(RangeBegin < RangeEnd)
        {
            T BaseElement = Partition(PtrToArray, RangeBegin,RangeEnd);
            QuickSort(PtrToArray, RangeBegin, BaseElement-1);
            QuickSort(PtrToArray, BaseElement, RangeEnd);
        }
    }

    static void MatrixQuickSort(Matrix<T>* PtrToMAtrix)
    {
        PtrToMAtrix->print_in_string();
        T temp_array[PtrToMAtrix->m_cols * PtrToMAtrix->m_rows];
        int count = 0;
        for(int i = 0; i < PtrToMAtrix->m_rows; i++ )
        {
            for(int j = 0; j < PtrToMAtrix->m_cols; j++)
            {
                temp_array[count] = PtrToMAtrix->get_value(i,j);
                count++;
            }
        }

        QuickSort(temp_array, 0, PtrToMAtrix->m_rows * PtrToMAtrix->m_cols);

        count = 0;
        for(int i = 0; i < PtrToMAtrix->m_rows; i++ )
        {
            for(int j = 0; j < PtrToMAtrix->m_cols; j++)
            {
                PtrToMAtrix->set_value(i,j,temp_array[count]);
                count++;
            }
        }
//        for(int i = 0; i < PtrToMAtrix->m_rows; i++)
//        {
//            QuickSort(PtrToMAtrix->m_matrix[i],0,PtrToMAtrix->m_cols);
//        }
        std::cout << "after" << std::endl;
        PtrToMAtrix->print_in_string();
    }
};

