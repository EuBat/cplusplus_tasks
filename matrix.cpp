#include "matrix.h"

int main()
{
    double arr1[4][4] {{1,-3,7,5},
                       {7,-1,9,6},
                       {3,-4,7,8},
                       {5,-6,7,8}};

    double arr2[4][4] {{-2,4,1,9},
                      {-5,2,1,7},
                      {-2,3,4,5},
                      {-4,5,6,7}};

    double arr3[5][2] {{1,-3},
                       {7,-1},
                       {3,-4},
                       {5,-6},
                       {7,8}};

    double arr4[2][4] {{-2,4,1,9},
                      {-5,2,1,7}};

    Matrix<double> test(&arr1[0][0],4,4);
    Matrix<double> test2(&arr2[0][0],4,4);
    Matrix<double> test_del(4,4);

    test.print_in_string();
     test = test/ 0;
//    test_del.print_in_string();
    test_del = test / test2;

    test.print_in_string();
    test_del.print_in_string();

    return 0;
}
