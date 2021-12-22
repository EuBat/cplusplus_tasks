#pragma once

#include <iostream>
#include <stdexcept>

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


class Zero_Determinate_Exception : public std::exception
{
public:
   Zero_Determinate_Exception(const char* message)
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
    Matrics_Wrong_Size_Exception(const char* message)
        :m_message(message){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

private:
    const char* m_message;
};

class Non_Square_Matrix_Exception : public std::exception
{
public:
    Non_Square_Matrix_Exception(const char* message)
        : m_message(message) {};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

private:
    const char* m_message;
};


class Overflow_Exception : public std::exception
{
public:
    Overflow_Exception(const char* message)
        : m_message(message){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

    void  what_arguments() const
    {
        std::cout << m_message << std::endl;
    };

private:
    const char* m_message;
};

class Underflow_Exception : public std::exception
{
public:
    Underflow_Exception(const char* message)
        : m_message(message){};

    virtual const char* what() const noexcept override
    {
        return m_message;
    };

    void  what_arguments() const
    {
        std::cout << m_message << std::endl;
    };

private:
    const char* m_message;
};
