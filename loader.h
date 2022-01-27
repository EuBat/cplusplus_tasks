#pragma once
#include <vector>
#include <fstream>
#include <iostream>


#include "matrix.h"

class Loader
{
public:
    ~Loader() = default;
    std::string mData;
    std::vector<char> mDataChar;
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
            std::cout << "Bad" << std::endl;
        }
        while(mFile)
        {
//            std::getline(mFile, mData);
            std::get
//            std::cout << mData << std::endl;
//            mData << getline()
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
