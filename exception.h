#pragma once

#include <iostream>

class Division_By_Zero_Exception : public std::exception
{
public:
    Division_By_Zero_Exception(){};

    virtual const char* what() const noexcept override
    {
        std::cerr << "Division by zero" << std::endl;

    // предупреждение, если нет возвращаемого значения
        return 0;
    };
private:
};

class Non_Square_Matrix_Exception : public std::exception
{
public:
    Non_Square_Matrix_Exception(std::string message, size_t rows, size_t cols)
        : m_message(message),
          m_rows(rows),
          m_cols(cols) {};

    virtual const char* what() const noexcept override
    {
        std::cerr << "\nError   ." << m_message
                  << "\nMatrix A size"
                  << "\nrows:   " << m_rows
                  << "\ncols:   " << m_cols << std::endl;
        return 0;
    };
private:
    std::string m_message;
    size_t m_rows;
    size_t m_cols;
};

class Matrics_Wrong_Size_Exception : public std::exception
{
public:
    Matrics_Wrong_Size_Exception(const std::string& message, size_t Matrix_A_rows, size_t Matrix_A_cols,
                                                             size_t Matrix_B_rows, size_t Matrix_B_cols)
        :m_message(message),
         m_Matrix_A_cols(Matrix_A_cols), m_Matrix_A_rows(Matrix_A_rows),
         m_Matrix_B_cols(Matrix_B_cols), m_Matrix_B_rows(Matrix_B_rows){};

//    Matrics_Wrong_Size_Exception(const std::stg mesasge, size_t Matrix_A_rows, size_t Matrix_A_cols):
//        :m_message(message);

    virtual const char* what() const noexcept override
    {
        std::cerr << "\nError.  " << m_message
                  << "\nMatrix A size"
                  << "\nrows:   " << m_Matrix_A_rows
                  << "\ncols:   " << m_Matrix_A_cols
                  << "\n\nMatrix B size"
                  << "\nrows:   " << m_Matrix_B_rows
                  << "\ncols:   " << m_Matrix_B_cols << std::endl;
        return 0;
    }
private:
    std::string m_message;
    size_t m_Matrix_A_cols;
    size_t m_Matrix_A_rows;
    size_t m_Matrix_B_cols;
    size_t m_Matrix_B_rows;

};

class Non_Digit_Exception : public std::exception
{
public:
    Non_Digit_Exception(const char symbol)
        :m_symbol(symbol){};

    virtual const char * what() const noexcept override
    {
        std::cerr << "\nError. Symbol \"" << m_symbol << "\"  is not a digit" << std::endl;
        return 0;
    };

private:
    const char m_symbol;
};


template <typename T>
class Overflow_Exception : public std::exception
{
public:
    Overflow_Exception(const std::string& message, const T arg_A,const T arg_B)
        : m_message(message), m_arg_A(arg_A), m_arg_B(arg_B){};

    Overflow_Exception(const std::string& message)
        : m_message(message){};
    virtual const char* what() const noexcept override
    {
        std::cerr << m_message
                  << "\nArgument 1: " << m_arg_A
                  << "\nArgument 2: " << m_arg_B << std::endl;
        return 0;
    };
private:
    std::string m_message{"no messege"};
    T m_arg_A;
    T m_arg_B;
};

template <typename T>
class Underflow_Exception : public std::exception
{
public:
    Underflow_Exception(const std::string& message, const T arg_A,const T arg_B)
        : m_message(message), m_arg_A(arg_A), m_arg_B(arg_B){};

    Underflow_Exception(const std::string& message)
        : m_message(message){};
    virtual const char* what() const noexcept override
    {
        std::cerr << m_message
                  << "\nArgument 1: " << m_arg_A
                  << "\nArgument 2: " << m_arg_B << std::endl;
        return 0;
    };
private:
    std::string m_message{"no messege"};
    T m_arg_A;
    T m_arg_B;
};
