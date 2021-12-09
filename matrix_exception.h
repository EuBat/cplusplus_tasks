#pragma once

#include <iostream>
#include <stdexcept>

// не полeчилось наследовать runtime_error
// как часто нужно использовать noexcept?
// спецификация исключений для функции просто для удобства?
// как сделать исключение(удалить) все конструторы типа Matrix<int> (...)

class Division_By_Zero_Exception : public std::exception
{
public:
    Division_By_Zero_Exception(const char* message)
        :m_message(message){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

private:
    const char* m_message;
};


class Zero_Determinate : public std::exception
{
public:
   Zero_Determinate(const char* message)
        :m_message(message){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

private:
    const char* m_message;
};

class Matrics_Wrong_Size_Exception : public std::exception
{
public:
    Matrics_Wrong_Size_Exception(const char* message, size_t Matrix_A_rows, size_t Matrix_A_cols,
                                                      size_t Matrix_B_rows, size_t Matrix_B_cols)
        :m_message(message),
         m_Matrix_A_cols(Matrix_A_cols), m_Matrix_A_rows(Matrix_A_rows),
         m_Matrix_B_cols(Matrix_B_cols), m_Matrix_B_rows(Matrix_B_rows){};

    Matrics_Wrong_Size_Exception(const char* message) : Matrics_Wrong_Size_Exception(message, 0, 0, 0, 0){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

    void  what_sizes_of_matrices() const
    {
        std::cout << "\nMatrix A"
                  << "\nrows    " << m_Matrix_A_rows
                  << "\ncols    " << m_Matrix_A_cols
                  << "\nMatrix B"
                  << "\nrows    " << m_Matrix_B_rows
                  << "\ncols    " << m_Matrix_B_cols << std::endl;
    };

private:
    const char* m_message;
    size_t m_Matrix_A_cols;
    size_t m_Matrix_A_rows;
    size_t m_Matrix_B_cols;
    size_t m_Matrix_B_rows;
};

class Non_Square_Matrix_Exception : public std::exception
{
public:
    Non_Square_Matrix_Exception(const char* message, size_t rows, size_t cols)
        : m_message(message),
          m_rows(rows),
          m_cols(cols) {};

    Non_Square_Matrix_Exception(const char* message) : Non_Square_Matrix_Exception(message, 0,0){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

    void  what_sizes_of_matrix() const
    {
        std::cout << "\nMatrix"
                  << "\nrows    " << m_rows
                  << "\ncols    " << m_cols << std::endl;
    };

private:
    const char* m_message;
    size_t m_rows;
    size_t m_cols;
};


template <typename T>
class Overflow_Exception : public std::exception
{
public:
    Overflow_Exception(const char* message, const T arg_A,const T arg_B)
        : m_message(message), m_arg_A(arg_A), m_arg_B(arg_B){};

    Overflow_Exception(const char* message) : Overflow_Exception(message, 0, 0){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

    void  what_arguments() const
    {
        std::cout << "\nArgument A"
                  << m_arg_A
                  << "\nArgument B"
                  << m_arg_B << std::endl;
    };

private:
    const char* m_message;
    T m_arg_A;
    T m_arg_B;
};

template <typename T>
class Underflow_Exception : public std::exception
{
public:
    Underflow_Exception(const char* message, const T arg_A,const T arg_B)
        : m_message(message), m_arg_A(arg_A), m_arg_B(arg_B){};

    Underflow_Exception(const char* message) : Underflow_Exception(message, 0, 0){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

    void  what_arguments() const
    {
        std::cout << "\nArgument A"
                  << m_arg_A
                  << "\nArgument B"
                  << m_arg_B << std::endl;
    };

private:
    const char* m_message;
    T m_arg_A;
    T m_arg_B;
};
