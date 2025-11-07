// ExploreRandom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void drawLine();
void printRandNumber();
void printRandIntInRange();
void printRandFloat();

int main()
{
    srand(int(time(nullptr)));
    drawLine();
    printRandNumber();
    drawLine();
    printRandIntInRange();
    drawLine();
    printRandFloat();
    drawLine();
}

void drawLine() {
    std::cout << "\n---------------------------\n\n";
}

void printRandNumber() {
    std::cout << std::rand() << std::endl;
    std::cout << std::rand() << std::endl;
    std::cout << std::rand() << std::endl;
    std::cout << std::rand() << std::endl;
}

void printRandIntInRange() {
    std::cout << std::rand() % 51 << std::endl; // 0 to 50
    std::cout << std::rand() % 71 + 10 << std::endl; // 10 to 80
    std::cout << std::rand() % 41 - 20 << std::endl; // -20 to 20
    std::cout << std::rand() % 5 - 2 << std::endl; // -2 to 2
}


void printRandFloat() {
    std::cout << std::rand() % 501 / float(100) + 5 << std::endl; // 5.00 to 10.00
    std::cout << std::rand() % 1001 / float(100) - 5 << std::endl; // -5.00 to 5.00w
}
