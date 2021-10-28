#pragma once

#include <iostream>

class Exception_Memory : public std::exception
{
public:
    Exception_Memory(){};
    ~ Exception_Memory(){};

private:

};

class Exception_Division : public std::exception
{
public:
    Exception_Division(){};
    ~ Exception_Division(){};
private:

};
