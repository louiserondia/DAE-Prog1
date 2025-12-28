// Rondia, Louise, 1DAE12

#include "pch.h"
#include <iostream>

void ExploreString(std::string& str);

int main()
{
    std::string str{ "\"Our Vanishing Wild Life : Its Extermination and Preservation\" by William T. Hornaday" };

    ExploreString(str);
}

void ExploreString(std::string& str) {
    std::cout << str << std::endl;
    std::cout << "size : " << str.size() << std::endl;
    std::cout << "length : " << str.length() << std::endl;
    std::cout << "capacity : " << str.capacity() << std::endl;

    const char* cstr{ str.c_str() };
    for (size_t i{}; i < str.size(); ++i) {
        std::cout << cstr[i] << "_";
    }
    std::cout << std::endl;

    std::cout << "str[0] " << str[0] << std::endl;
    std::cout << "str.at(0) "<< str.at(0) << std::endl;
    std::cout << "str[str.size() - 1] " << str[str.size() - 1] << std::endl;
    std::cout << "str.at(str.size() - 1) "<< str.at(str.size() - 1) << std::endl;
}

