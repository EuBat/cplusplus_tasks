#pragma once
#include <vector>
//#include <iostream>
#include <fstream>


#include "matrix.h"

class Loader
{
public:
    ~Loader() = default;
    std::vector<std::string>  mData;
};

class FileLoader: public Loader
{
public:
    FileLoader(const std::string& FileName)
        :mFileName(FileName)
    {
        mFile.open(mFileName,std::ios::out);
        if(!mFile.is_open())
        {
            std::cout << "Bad" << std::endl;
        } else
        {
            mFile.getline();
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
