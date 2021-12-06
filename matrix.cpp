 #include "matrix.h"

int main()
{
    int arr1[4][4] {{1,-3,7,5},
                       {7,-1,9,6},
                       {3,-4,7,8},
                       {5,-6,7,8}};

    double arr2[4][4] {{-2,4,1,9},
                      {-5,2,1,7},
                      {-2,3,4,5},
                      {-4,5,6,7}};

    int arr3[5][2] {{1,1},
                    {1,1},
                    {1,22},
                    {1,1},
                    {1,1}};

    double arr4[2][4] {{-2,4,1,9},
                      {-5,2,1,7}};

    double arr5[5][2] {{1,-3},
                       {7,-1},
                       {3,-4},
                       {5,-6},
                       {3,1}};
    char const*array = "3,3,3,3,3,33333,3,3,3";
    Matrix<double> test4(array,3,3);

    Matrix<int> test(&arr1[0][0],4,4);
    Matrix<int> test2(&arr3[0][0],5,2);
    Matrix<double> test_del(4,4);
    test2 = test2 * (2147483646);
    //test4.print_in_string();
//    test.print_in_string();
//    test2 * test;
//    test_del.print_in_string();
//    test_del = test / test2;
    std::cout << std::numeric_limits<int>::max() << std::endl;
    test2.print_in_string();
    test.print_in_string();
    test_del.print_in_string();

    return 0;
}
