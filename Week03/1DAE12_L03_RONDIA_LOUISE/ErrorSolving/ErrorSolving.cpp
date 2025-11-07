#include <iostream>
#include <string>

int main()
{
	srand(int(time(nullptr)));

	// 1. Calculate average result of 3 tests
	int total{}, testResult{};
	std::cout << "The 1st test result? ";
	std::cin >> testResult;
	total += testResult;

	std::cout << "The 2nd test result? ";
	std::cin >> testResult;
	total += testResult;

	std::cout << "The 3rd test result? ";
	std::cin >> testResult;
	total += testResult;
	std::cout << "Total: " << total << std::endl;

	float average{ total / 3.0f };
	std::cout << "Average result: " << average << std::endl;

	// 2. Generate 3 random numbers in the range [3,6]
	std::cout << "\nRandom numbers in the range [3, 6]\n";
	int a{ 4 };
	int b{ 3 };
	int randNr = rand() % a + b;
	std::cout << randNr << std::endl;
	randNr = rand() % a + b;
	std::cout << randNr << std::endl;
	randNr = rand() % a + b;
	std::cout << randNr << std::endl;

	// 3. Square root function: sqrt
	float floatResult{};
	float floatNr{};

	std::cout << "Enter a floating point value ";
	std::cin >> floatNr;
	floatResult = sqrt(floatNr);
	std::cout << "Square root of this value is " << floatResult << std::endl;

	int intNr{};
	double doubleResult{};

	std::cout << "Enter an integer value ";
	std::cin >> intNr;
	doubleResult = sqrt(intNr);
	std::cout << "Square root of this value is " << doubleResult << std::endl;


	// 4. Print ASCII value of the entered letter
	std::cout << "Enter a letter ";
	char letter{};
	std::cin >> letter;
	std::cout << "ASCII value of this letter is " << int(letter) << std::endl;


	// 5. Print letter of the entered ASCII value
	std::cout << "Enter ASCII value of a letter ";
	int ascii{};
	std::cin >> ascii;
	std::cout << "Letter " << ascii << " corresponds with this ASCII value: " << char(ascii) << std::endl;

	// 6. Wait until user presses ENTER
	std::cin.ignore(1, '\n');
	std::cout << "\nPush ENTER to quit\n";
	std::cin.get();

	return 0;

}