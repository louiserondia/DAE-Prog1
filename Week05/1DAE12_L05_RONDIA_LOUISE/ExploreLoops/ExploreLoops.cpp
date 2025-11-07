// ExploreLoops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#define M_PI       3.14159265358979323846f

void    PrintEven();
void    PrintExamScores();
void	RandomGuess();
void	PrintTrigonometry();
void	PrintAscii();

int main()
{
	srand(time(nullptr));
	PrintEven();
	PrintExamScores();
	RandomGuess();
	PrintTrigonometry();
	PrintAscii();
}

void    PrintEven() {
	for (int index = 1; index <= 12; index++) {
		std::cout << index * 2 << " ";
	}
	std::cout << std::endl;

	int index{ 1 };

	while (index <= 12)
	{
		std::cout << index * 2 << " ";
		index++;
	}
	std::cout << std::endl;

	index = 1;
	do
	{
		std::cout << index * 2 << " ";
		index++;
	} while (index <= 12);
	std::cout << std::endl;
}

static void	PrintResult(int letter, std::string str) {
	std::cout << str << " : " << letter << std::endl;
}

void    PrintExamScores() {
	int score{}, totalScore{};
	int a{}, aPlus{}, b{}, c{}, d{}, e{}, fX{}, f{};
	std::string	allScores{};

	while (score != -1) {
		std::cout << "score [0, 20] ? ";
		std::cin >> score;

		if (score > 20 || score < -1) {
			std::cout << "Wrong score!\n";
			continue;
		}

		if (score > 17)
			++aPlus;
		else if (score > 15)
			++a;
		else if (score > 14)
			++b;
		else if (score > 12)
			++c;
		else if (score > 10)
			++d;
		else if (score > 9)
			++e;
		else if (score > 7)
			++fX;
		else if (score > 0)
			++f;
		else if (score == -1)
			break;

		totalScore += score;
		if (allScores == "")
			allScores += std::to_string(score);
		else
			allScores += ", " + std::to_string(score);
	}

	PrintResult(aPlus, "A+");
	PrintResult(a, "A");
	PrintResult(b, "B");
	PrintResult(c, "C");
	PrintResult(d, "D");
	PrintResult(e, "E");
	PrintResult(fX, "FX");
	PrintResult(f, "F");
	std::cout << "Total score : " << totalScore << std::endl;
	std::cout << "Entered scores : " << allScores << std::endl;
}

void	RandomGuess() {
	int guess{}, count{};
	std::cout << "-- Guess number -- \nNumber to guess ? ";

	std::cin >> guess;
	while (guess < 0 || guess > RAND_MAX) {
		std::cout << "This is a wrong number. Number to guess ? ";
		std::cin >> guess;
	}

	while (rand() != guess) {
		++count;
	}
	std::cout << "Number found after " << count << " guesses\n";
}


void	PrintTrigonometry() {
	std::cout << "-- Trigonometry --\n";
	std::cout << std::right
		<< std::setw(10) << "Degrees"
		<< std::setw(10) << "Radians"
		<< std::setw(10) << "Cos"
		<< std::setw(10) << "Sin"
		<< std::endl;

	for (int index = 0; index <= 180; index += 10) {
		float rad{ index / 180.f * M_PI };
		std::cout << std::right << std::fixed
			<< std::setw(10) << std::setprecision(2) << index
			<< std::setw(10) << std::setprecision(2) << rad
			<< std::setw(10) << std::setprecision(2) << cos(rad)
			<< std::setw(10) << std::setprecision(2) << sin(rad)
			<< std::endl;
	}
}

void	PrintAscii() {
	std::cout << "-- ASCII table --\n";

	char a{ 'a' };
	char n{ 'n' };

	for (int index = 0; index < 13; ++index) {

		std::cout << std::right
			<< char(index + a)
			<< std::setw(10) << index + a
			<< std::setw(5) << char(index + n)
			<< std::setw(10) << index + n
			<< std::endl;
	}
}