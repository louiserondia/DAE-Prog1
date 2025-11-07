// 1DAE12, Rondia, Louise

#include <iostream>
#include <string>

void drawLine();
void printAsciiFromInt();
void emailAdressGenerator();
void createRhyme();
void intFloatCat();


int main()
{
	printAsciiFromInt();
	drawLine();
	emailAdressGenerator();
	drawLine();
	createRhyme();
	intFloatCat();
}

void drawLine() {
	std::cout << "\n---------------------------\n\n";
}

void printAsciiFromInt() {
	int input{};
	std::cout << "Hello please enter a number between 0 and 255: ";
	std::cin >> input;
	std::cout << "Number " << input << " is equivalent to " << char(input) << " in the ASCII table\n";
}

void emailAdressGenerator() {
	std::string firstName{}, lastName{};
	std::cout << "Hello please enter your first name: ";
	std::cin >> firstName;
	std::cout << "and your last name: ";
	std::cin >> lastName;
	std::cout << "HERE IS YOUR EMAIL ADRESS THEN: " << firstName + '.' + lastName + "@howest.student.be\n";
}

void createRhyme() {
	std::string noun{}, adj{}, rhyme{};
	int number;
	std::cout << "Hello please enter a noun, an adjective and a number: ";
	std::cin >> noun >> adj >> number;

	rhyme = std::to_string(number) + ' ' + adj + ' ' + noun;
	rhyme += ", lined up in a row.\nOne loves walking dead, so it got a bow.\nKilled one with an arrow, right up in its head.\nNow there's only ";
	rhyme += std::to_string(number - 1);
	rhyme += " alive in walking dead. \n";
	std::cout << rhyme << std::endl;
}

void intFloatCat() {
	int integerInput{};
	float floatInput{};
	std::cout << "Hello please enter an integer: ";
	std::cin >> integerInput;
	std::cout << "Now a float please: ";
	std::cin >> floatInput;
	std::cout << '\"' << integerInput << "\" + \"" << floatInput << "\" = " << std::to_string(integerInput) + std::to_string(floatInput) << std::endl;
	std::cout << integerInput << " + " << floatInput << " = " << integerInput + floatInput << std::endl;
}
