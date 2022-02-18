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
void QuickSort(T* PtrToArray, size_t RangeBegin, size_t RangeEnd )
{
    T BaseElment {&PtrToArray(RangeEnd)};
    for(int i = RangeEnd)
}

template<typename T>
void MatrixQuickSort(Matrix<T>* PointToMatrix)
{
  PointToMatrix->print_in_string();
  T BaseElement = PointToMatrix->get_value(rows-1, cols-1);
  unsigned int count = 0;
  for(int i = 0; i < rows; i++)
  {
      for(int j = 0;j < cols; j++)
      {
          if(PointToMatrix->get_value(rows-1, cols-1) <= BaseElement)
          {

          }
      }
  }
  std::cout << ">BaseElement = " <<BaseElement << std::endl;
};
//private:
//};

//class UsualSort
//{
//public:
//private:
//};
