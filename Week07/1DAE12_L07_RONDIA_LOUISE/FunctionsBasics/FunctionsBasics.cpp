// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Rondia, Louise, 1DAE12

#include "pch.h"
#include <iostream>
#include <string>
#include <chrono>
//#include <time.h>

struct Point2f
{
	float x;
	float y;
};

void	ComputeCosSin(const float angle, float& cos, float& sin);
void	PrintComputeCosSin();
void	PrintValue(int value, char delimiter = ' ');
void	PrintValue(char value, char delimiter = ' ');
void	PrintValue(float value, char delimiter = ' ');
void	TestPrint();

int main()
{
	srand(unsigned int(time(0)));

	//TestPrint();
	PrintComputeCosSin();
}

void PrintValue(int value, char delimiter)
{
	std::cout << value << delimiter;
}

void PrintValue(char value, char delimiter)
{
	std::cout << value << delimiter;
}

void PrintValue(float value, char delimiter)
{
	std::cout << value << delimiter;
}

void TestPrint()
{
	PrintValue('a', ',');
	PrintValue('a');
	PrintValue(20, ',');
	PrintValue(20);
	PrintValue(20.0f, ',');
	PrintValue(20.0f);
}

void ComputeCosSin(const float angle, float& cos, float& sin) {
	cos = cosf(angle);
	sin = sinf(angle);
}

void PrintComputeCosSin() {
	float cos{}, sin{}, angle{};

	std::cout <<" Function that calculates cosine and sine\n Radians  	Cos  	Sin" << std::endl;
	for (int i{}; i < 10; ++i) {
		angle = static_cast<float>(rand()) / RAND_MAX * 3.1415;
		ComputeCosSin(angle, cos, sin);

		std::cout << angle << " 	" << cos << "  	" << sin << std::endl;
	}
}