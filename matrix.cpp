#include "matrix.h"
#include "loader.h"
#include <locale>

int main()
{
    double arr1[4][4] {{1,0,0,5},
                      {7,0,9,6},
                      {3,-4,8,8},
                      {5,-6,7,8}};

    double arr2[4][4] {{4,4,1,9},
                      {-5,3,4,7},
                      {-2,3,3,5},
                      {-4,5,6,3}};

    Matrix<double> test(&arr2[0][0],3,4);
    Matrix<double> test2(&arr1[0][0],4,4);

    try {
        std::cout <<" det = " << test.get_determinant() << std::endl;
    } catch(Non_Square_Matrix_Exception& exception) {
        std::cout << exception.what() << std::endl;
    } catch(...)
    {
        std::cout << "wtf" << std::endl;
    }

    try
    {
        test2 = test2.get_inverse_matrix();
    } catch(Non_Square_Matrix_Exception& exception) {
        std::cout << exception.what() << std::endl;
    } catch(...)
    {
        std::cout << "wtf" << std::endl;
    }

//    ConsoleLoader LoadFromConcole;
    try
    {
        FileLoader LoadFromFile("C://Qt/project/task7/matrix in.txt");
        Matrix<double> MatrixFile(LoadFromFile.getData());
    } catch (FileOpen_Exception exception)
    {
        std::cout << exception.what() << std::endl;
    } catch (UncorrectInputData_Exception exception)
    {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}
