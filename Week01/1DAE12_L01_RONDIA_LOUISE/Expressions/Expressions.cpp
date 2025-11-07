// Rondia, Louise - 1DAE12

#include <iostream>

int main()
{
    int number{ 4 };
    float floatNumber{ .3f };
    char letter{ 'C' };
    
    std::cout << "+ and - operators" << std::endl;

    std::cout << "the result of " << number << " + " << 9 << " = " << number + 9 << std::endl;
    std::cout << "the result of " << floatNumber << " - " << 9.1f << " = " << floatNumber - 9.1f << std::endl;
    std::cout << "the result of adding " << 32 << " to " << letter << " is " << letter + 32;
    std::cout << " and in ascii : " << char(letter + 32) << std::endl;
    std::cout << "the result of adding " << 32 << " and " << number << " to " << letter << " is " << letter + number + 32;
    std::cout << " and in ascii : " << char(letter + number + 32) << std::endl;

    std::cout << std::endl;
    std::cout << "* and / operators" << std::endl;

    std::cout << "the result of " << number << " * " << 9 << " = " << number * 9 << std::endl;
    std::cout << "the result of " << 9.f << " / " << floatNumber << " = " << 9.f / floatNumber << std::endl;
    std::cout << "the result of " << 9.f << " / " << floatNumber  << " * " << .5f << " / " << number << " = " << 9 / floatNumber * .5f / number << std::endl;

    std::cout << std::endl;
    std::cout << "Compound expressions" << std::endl;

    std::cout << "10 - 5 - 2 = " << 10 - 5 - 2 << std::endl;
    std::cout << "10 - (5 - 2) = " << 10 - (5 - 2) << std::endl;
    std::cout << "10 - 5 + 2 = " << 10 - 5 + 2 << std::endl;
    std::cout << "10 - (5 + 2) = " << 10 - (5 + 2) << std::endl;

    std::cout << std::endl;
    std::cout << "10 / 5 * 2 = " << 10 / 5 * 2 << std::endl;
    std::cout << "10 / (5 * 2) = " << 10 / (5 * 2) << std::endl;
    std::cout << "10 / 5 + 2 = " << 10 / 5 + 2 << std::endl;
    std::cout << "int(10) / (5 + 2) = " << 10 / (5 + 2) << std::endl;
    std::cout << "float(10) / (5 + 2) = " << 10.f / (5 + 2) << std::endl;

    std::cout << std::endl;
    std::cout << "compound assignment operators with number's value starting as " << number << std::endl;

    std::cout << "number += 3 sets number to ";
    number += 3;
    std::cout << number << std::endl;

    std::cout << "number -= 2 sets number to ";
    number -= 2;
    std::cout << number << std::endl;
    std::cout << "number *= 2 sets number to ";
    number *= 2;
    std::cout << number << std::endl;
    std::cout << "number /= 2 sets number to ";
    number /= 2;
    std::cout << number << std::endl;
    std::cout << "number %= 2 sets number to ";
    number %= 2;
    std::cout << number << std::endl;

    std::cout << std::endl;
    std::cout << "unary operators with number's value starting as " << number << std::endl;

    std::cout << "number++ :" << number++ << " and after operation, number = " << number << std::endl;
    std::cout << "++number :" << ++number << " and after operation, number = " << number << std::endl;
    std::cout << "number-- :" << number-- << " and after operation, number = " << number << std::endl;
    std::cout << "--number :" << --number << " and after operation, number = " << number << std::endl;



}
