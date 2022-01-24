#pragma once
#include <iostream>

class Loader {
public:
    ~Loader() = default;

    void SetFileName(const std::string& FileName)
        :mFileName(FileName){};
private:
    std::string mFileName;

};
git
