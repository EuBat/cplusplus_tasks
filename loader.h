#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>


#include "matrix.h"
#include "matrix_exception.h"

class Loader
{
public:
    ~Loader() = default;

    std::string getData() const
    {
        return mData;
    }

    size_t getCols() const
    {
        return mCols;
    }

    size_t getRows() const
    {
        return mRows;
    }
protected:
    std::string mData;
    size_t mCols, mRows;
};

class ConsoleLoader: public Loader
{
public:
    ConsoleLoader()
    {
        std::cout << "Set the matrix cols and rows\n";
        std::cin >> mCols >> mRows;
        while(!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input is not correct. Set the matrix cols and rows \n";
            std::cin  >> mCols >> mRows;
        }

        std::string CurrentLine;
        std::cout << "String format: a b c ... n, where a, b, c, n – number.\n";
        std::cin.ignore();
        for(int i = 1; i <= mRows; i++) {

            std::cout << "Set the marix rows # " << i << "\n";
            std::getline(std::cin,CurrentLine);
            mData.append(CurrentLine + ';');
        }
    };
};


class FileLoader: public Loader
{
public:
    FileLoader(const std::string& FileName)
        :mFileName(FileName)
    {
        mFile.open(mFileName,std::ios::in);
        if(!mFile.is_open())
        {
            throw(FileOpen_Exception("file do not open"));
        }
        else
        {
            std::string StringBuffer;
            while(std::getline(mFile,StringBuffer))
            {
                mData.append(StringBuffer);
            }
            mFile.close();
        }
    };

    std::string GetFileName() const
    {
        return mFileName;
    }

private:
    std::fstream mFile;
    std::string mFileName;

};
