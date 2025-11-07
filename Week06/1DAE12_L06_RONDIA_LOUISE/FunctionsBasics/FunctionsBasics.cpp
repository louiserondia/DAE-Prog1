// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

int		Sum(int a, int b);
void	TestSum();
int		Multiply(int a, int b);
void	TestMultiply();
int		Modulo(int value, int divider);
void	TestModulo();
void	PrintNumbers(int start, int end);
void	TestPrintNumbers();
float	CalcElapsedTime(int rangeStart, int rangeEnd);
void	PrintCalcElapsedTime();
void	PrintMessage(std::string message, int numSpace);
void	TestPrintMessage();
bool	IsEven(int number);
void	TestIsEven();
//bool	IsLeap(); // done in previous lab
//void	TestIsLeap();
float	GetRand();
int		GetRand(int start, int end);
float	GetRand(float start, float end);
void	TestGetRand();
float	GetDistance(float x1, float y1, float x2, float y2);
float	GetDistance(Point2f p1, Point2f p2);
void	TestGetDistance();
void	PrintValue(int value, char delimiter);
void	PrintValue(char value, char delimiter);
void	PrintValue(float value, char delimiter);
void	TestPrint();

int main()
{
	srand(unsigned int(time(0)));

	//TestPrint();
	//TestSum();
	//TestMultiply();
	//TestModulo();
	//TestPrintNumbers();
	//PrintCalcElapsedTime();
	//TestPrintMessage();
	//TestIsEven();
	//TestGetRand();
	TestGetDistance();
}

int Sum(int a, int b) {
	return a + b;
}

void TestSum() {
	int a{}, b{}, c{}, d{};

	std::cout << "-- Function that calculates the sum of 2 integers --\n";
	std::cout << "2 numbers to add ? ";
	std::cin >> a >> b;
	std::cout << a << " + " << b << " = " << Sum(a, b) << std::endl;

	std::cout << "4 numbers to add ? ";
	std::cin >> a >> b >> c >> d;
	std::cout << a << " + " << b << " + " << c << " + " << d << " = " << Sum(Sum(a, b), Sum(c, d)) << std::endl;

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
	PrintValue(20, ',');
	PrintValue(20.0f, ',');
}

int Multiply(int a, int b) {
	return a * b;
}

void TestMultiply()
{
	int a{}, b{}, c{}, d{};

	std::cout << "-- Function that calculates the product of 2 integers --\n";
	std::cout << "2 numbers to multiply ? ";
	std::cin >> a >> b;
	std::cout << a << " * " << b << " = " << Multiply(a, b) << std::endl;

	std::cout << "4 numbers to multiply ? ";
	std::cin >> a >> b >> c >> d;
	std::cout << a << " * " << b << " * " << c << " * " << d << " = " << Multiply(Multiply(a, b), Multiply(c, d)) << std::endl;
}

int Modulo(int value, int divider) {
	if (value - divider < 0)
		return value;
	return Modulo(value - divider, divider);
}

void TestModulo()
{
	int a{}, b{}, c{}, d{};

	std::cout << "-- Function that calculates the modulo of 2 integers --\n";
	std::cout << "2 numbers to doluldo ? ";
	std::cin >> a >> b;
	std::cout << a << " % " << b << " = " << Modulo(a, b) << std::endl;

	std::cout << "4 numbers to dododulo ? ";
	std::cin >> a >> b >> c >> d;
	std::cout << "(" << a << " % " << b << ") % (" << c << " % " << d << ") = " << Modulo(Modulo(a, b), Modulo(c, d)) << std::endl;
}

void	PrintNumbers(int start, int end) {
	for (int i{ start }; i <= end; ++i) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
void	TestPrintNumbers() {
	int start{}, end{};

	std::cout << "-- Function that print numbers in a range --\n";
	std::cout << "start and end of range? ";
	std::cin >> start >> end;
	std::cout << "Interval [" << start << ", " << end << "] = ";
	PrintNumbers(start, end);
}

float	CalcElapsedTime(int rangeStart, int rangeEnd) {
	const std::chrono::steady_clock::time_point startTime{ std::chrono::steady_clock::now() };

	PrintNumbers(rangeStart, rangeEnd);

	const std::chrono::steady_clock::time_point endTime{ std::chrono::steady_clock::now() };
	const std::chrono::duration<float, std::milli> elapsedTime{ endTime - startTime };
	return elapsedTime.count();
}

void	PrintCalcElapsedTime() {
	int start{}, end{};

	std::cout << "-- Function that print the time it take to print numbers in a range --\n";
	std::cout << "start and end of range? ";
	std::cin >> start >> end;
	std::cout << "\nThis print task took : " << CalcElapsedTime(start, end) << " miliseconds" << std::endl;
}

void	PrintMessage(std::string message, int numSpace) {
	for (int i{}; i < numSpace; ++i) {
		std::cout << " ";
	}

	std::cout << message << std::endl;
}

void	TestPrintMessage() {
	int numSpace{};

	std::cout << "-- Function that prints a message with indentation.s --\n";
	PrintMessage("No indentation", 0);
	PrintMessage("2 indentations", 2);
	PrintMessage("4 indentations", 4);

}

bool	IsEven(int number) {
	return !(number & 1);
}

void	TestIsEven() {
	int number{};

	std::cout << "-- Function that prints if a number is even (or odd) --\n";
	std::cout << "Enter a number : ";
	std::cin >> number;

	switch (IsEven(number))
	{
	case 0:
		std::cout << number << " is odd" << std::endl;
		break;
	default:
		std::cout << number << " is even" << std::endl;
		break;
	}
}

float	GetRand() {
	return (float)(rand()) / (float)(RAND_MAX);
}

float	GetRand(float start, float end) {
	return GetRand() * (end - start) + start;
}

int		GetRand(int start, int end) {
	return int(GetRand(float(start), float(end)));
}

void TestGetRand() {
	int a{}, b{};
	float c{}, d{};

	std::cout << "-- Function that prints a random number in a range --\n";
	std::cout << "Enter a range with 2 integers :";
	std::cin >> a >> b;
	std::cout << "random number in [" << a << ", " << b << "] : " << GetRand(a, b) << std::endl;

	std::cout << "Enter a range with 2 floats :";
	std::cin >> c >> d;
	std::cout << "random number in [" << c << ", " << d << "] : " << GetRand(c, d) << std::endl;
}

float GetDistance(float x1, float y1, float x2, float y2) {
	float distX{ x1 - x2 }, distY{ y1 - y2 };

	return sqrtf(distX * distX + distY * distY);
}

float GetDistance(Point2f p1, Point2f p2) {
	return GetDistance(p1.x, p1.y, p2.x, p2.y);
}

void TestGetDistance() {
	float a{ 0.41f }, b{ 184.67f }, c{ 63.34f }, d{ 265.f };
	Point2f p1{ a, b }, p2{ c, d };

	std::cout << "-- Function that prints distance between 2 points --\n";
	std::cout << "Distance between [" << a << ", " << b << "] and [" << c << ", " << d << "]" << std::endl;

	std::cout << "Using one version: " << GetDistance(a, b, c, d) << std::endl;
	std::cout << "Using the other version: " << GetDistance(p1, p2) << std::endl;
}

