#pragma once
#include "matrix.h"

//class Sort
//{
//  ~Sort() = default;
//};

//class QuickSort:public Sort
//{
//public:

template<typename T>
T Partition(T* PtrToArray, size_t RangeBegin, size_t RangeEnd )
{
    std::cout << "Before partition\n";
    for(int k = RangeBegin; k < RangeEnd; k++)
    {
        std::cout << "  "<< *(PtrToArray+k);
    }
    std::cout << "> \n" << std::endl;
    std::cout << "Range Begin " << RangeBegin << std::endl;
    std::cout << "Range End   " << RangeEnd   << std::endl;

    T BaseElement {*(PtrToArray+RangeEnd-1)};
    std::cout << "> Base Element = " << *(PtrToArray+RangeEnd-1) << std::endl;
    T TempElement {0};
    size_t i {RangeBegin};
    for(int j = RangeBegin; j < RangeEnd; j++)
    {
        std::cout << "> j =     " << *(PtrToArray+j) << "\n";
        if(*(PtrToArray+j) <= BaseElement)
        {
            TempElement = *(PtrToArray + i);
            *(PtrToArray + i)  = *(PtrToArray + j) ;
            *(PtrToArray + j)  = TempElement;
            i++;
            std::cout << "x> i =     " << i << "     " <<  *(PtrToArray+i) << "\n";
        }
    }
    std::cout << "> after partition\n";
    for(int k = RangeBegin; k<RangeEnd; k++)
    {
        std::cout << "  "<< *(PtrToArray+k);
    }
    std::cout << "> \n" << std::endl;
//    TempElement = *(PtrToArray + i);
//    *(PtrToArray + i) = BaseElement;
//    *(PtrToArray+RangeEnd) = TempElement;
//    std::cout << "> after base elemte\n";
//    for(int i = 0; i<8; i++)
//    {
//        std::cout << "  "<< *(PtrToArray+i);
//    }
//    std::cout << "> \n" << std::endl;
    return i;
}

template<typename T>
void QuickSort(T* PtrToArray, size_t RangeBegin, size_t RangeEnd)
{
    if(RangeBegin < RangeEnd)
    {
        T BaseElement = Partition(PtrToArray, RangeBegin,RangeEnd);
        QuickSort(PtrToArray, RangeBegin, BaseElement-1);
        QuickSort(PtrToArray, BaseElement, RangeEnd);
    }
}
//template<typename T>
//void MatrixQuickSort(Matrix<T>* PointToMatrix)
//{
//  PointToMatrix->print_in_string();
//  T BaseElement = PointToMatrix->get_value(rows-1, cols-1);
//  unsigned int count = 0;
//  for(int i = 0; i < rows; i++)
//  {
//      for(int j = 0;j < cols; j++)
//      {
//          if(PointToMatrix->get_value(rows-1, cols-1) <= BaseElement)
//          {

//          }
//      }
//  }
//  std::cout << ">BaseElement = " <<BaseElement << std::endl;
//};
//private:
//};

//class UsualSort
//{
//public:
//private:
//};
