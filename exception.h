#pragma once

#include <iostream>

class Matrix_Exceprions
{
public:
    virtual ~Matrix_Exceprions() {};
    virtual void what() const = 0;
};

class Exception_Division_By_Zero : public Matrix_Exceprions
{
public:
    Exception_Division_By_Zero(){};
    virtual ~Exception_Division_By_Zero(){};
    void what() const override
    {
        std::cerr << "Division by zero" << std::endl;
    }
private:
};

class Exception_Matrix_Size : public Matrix_Exceprions
{
public:
    Exception_Matrix_Size(size_t rows, size_t cols)
        : m_rows(rows),
          m_cols(cols) {};
    virtual ~Exception_Matrix_Size(){};
    void what() const override
    {
        std::cerr << "Matrix must be square\n"
                  << "\ncurrent size"
                  << "\nrows:   " << m_rows
                  << "\ncols:   " << m_cols << std::endl;
    }
private:
    size_t m_rows{0};
    size_t m_cols{0};
};

class Exception_Matrix_Multiple : public Matrix_Exceprions
{
public:
    Exception_Matrix_Multiple(size_t rows, size_t cols)
        : m_rows(rows),
          m_cols(cols) {};
    virtual ~Exception_Matrix_Multiple(){};
    void what() const override
    {

    }
private:
    size_t m_rows{0};
    size_t m_cols{0};
};

class Exception_Memory : public Matrix_Exceprions
{
public:
    Exception_Memory(){};
    virtual ~Exception_Memory(){};
    void what() const override
    {
        std::cout << "Some error with memory" << std::endl;
    }
private:
};
