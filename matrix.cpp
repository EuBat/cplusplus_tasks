 #include "matrix.h"

int main()
{
    int arr1[4][4] {{1,-3,7,5},
                    {7,-1,9,6},
                    {3,-4,7,8},
                    {5,-6,7,8}};

    double arr2[4][4] {{4,4,1,9},
                      {-5,3,4,7},
                      {-2,3,3,5},
                      {-4,5,6,3}};

    double arr3[3][3] {{-5,2,3},
                       {4,-5,6},
                       {7,-8,9}};

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
    Matrix<double> test2(&arr5[0][0],5,5);
    Matrix<double> test_del(4,4);

    try {
        std::cout <<" det = " <<test2.get_determinant() << std::endl;
//        test2 = test2.get_inverse_matrix();
    } catch(Non_Square_Matrix_Exception& exception) {
        std::cout << exception.what() << std::endl;
    } catch(Zero_Determinate_Exception& exception)
    {
        std::cout << exception.what() << std::endl;
    } catch(...)
    {
        std::cout << "wtf" << std::endl;
    }

    test2.print_in_string();

    return 0;
}
