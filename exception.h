#pragma once

#include <iostream>

//class Matrix_Exceprions
//{
//public:
//    virtual ~Matrix_Exceprions() {};
//    virtual void what() const = 0;
//};

class Division_By_Zero_Exception : public std::exception
{
public:
    Division_By_Zero_Exception(){};

    //virtual const char* what() const throw()
    virtual const char* what() const noexcept override
    {
        std::cerr << "Division by zero" << std::endl;
    };
private:
};

class Non_Square_Matrix_Exception : public std::exception
{
public:
    Non_Square_Matrix_Exception(size_t rows, size_t cols)
        : m_rows(rows),
          m_cols(cols) {};

    virtual const char* what() const noexcept override
    {
        std::cerr << "\nError. Matrix A is not-square. Determinate and inverse matrix of A does not exist"
                  << "\nMatrix A size"
                  << "\nrows:   " << m_rows
                  << "\ncols:   " << m_cols << std::endl;
    };
private:
    size_t m_rows;
    size_t m_cols;
};

class Un_Memory_Exception : public std::exception
{
    public:
        Non_Memory_Exception(){}
        virtual const char * what() const noexcept override
        {
            std::cerr << "No"
        };
}
//{
//public:
//    Exception_Matrix_Multiple(size_t A_rows, size_t A_cols, size_t B_rows, size_t B_cols)
//        : m_A_rows(A_rows),
//          m_A_cols(A_cols),
//          m_B_rows(B_rows),
//          m_B_cols(B_cols) {};
//    virtual ~Exception_Matrix_Multiple(){};
//    void what() const override
//    {
//        std::cerr << "\nError. Matrix miltiplication AxB can't be complete"
//                  << "\nMatrix A size"
//                  << "\nrows:   " << m_A_rows
//                  << "\ncols:   " << m_A_cols
//                  << "\n\nMatrix B size"
//                  << "\nrows:   " << m_B_rows
//                  << "\ncols:   " << m_B_cols << std::endl;
//    }
//private:
//    size_t m_A_rows{0};
//    size_t m_A_cols{0};
//    size_t m_B_rows{0};
//    size_t m_B_cols{0};
//};

//class Exception_Memory : public Matrix_Exceprions
//{
//public:
//    Exception_Memory(){};
//    virtual ~Exception_Memory(){};
//    void what() const override
//    {
//        std::cout << "Some error with memory" << std::endl;
//    }
//private:
//};
