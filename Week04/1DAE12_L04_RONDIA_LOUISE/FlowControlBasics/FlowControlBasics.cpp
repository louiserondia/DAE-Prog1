// FlowControlBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

void PrintTruthTable();
void CompareTwoNumbers();
void ConvertDayNumber();
void CheckLeapYear();
void ConvertSeconds();
void DefineUseActorState();
void DefineUsePoint2f();

int main()
{
	srand(unsigned int(time(nullptr)));
	PrintTruthTable();
	CompareTwoNumbers();
	ConvertDayNumber();
	CheckLeapYear();
	ConvertSeconds();
	DefineUseActorState();
	DefineUsePoint2f();
}


void PrintTruthTable() {
	const bool trueValue{ true };
	const bool falseValue{ false };

	std::cout << "-- Print truth table -- \n";

	std::cout << "\nLogical AND-operator (&&) \n";
	std::cout << " true && true is " << ((trueValue && trueValue) == true ? "true" : "false") << std::endl;
	std::cout << " true && false is " << ((trueValue && falseValue) == true ? "true" : "false") << std::endl;
	std::cout << " false && true is " << ((falseValue && trueValue) == true ? "true" : "false") << std::endl;
	std::cout << " false && false is " << ((falseValue && falseValue) == true ? "true" : "false") << std::endl;

	std::cout << "\nLogical binary OR-operator (||) \n";
	std::cout << " true && true is " << ((trueValue || trueValue) == true ? "true" : "false") << std::endl;
	std::cout << " true && false is " << ((trueValue || falseValue) == true ? "true" : "false") << std::endl;
	std::cout << " false && true is " << ((falseValue || trueValue) == true ? "true" : "false") << std::endl;
	std::cout << " false && false is " << ((falseValue || falseValue) == true ? "true" : "false") << std::endl;

	std::cout << "\nLogical unary NOT-operator (!) \n";
	std::cout << " !true is " << (!trueValue == true ? "true" : "false") << std::endl;
	std::cout << " !false is " << (!falseValue == true ? "true" : "false") << std::endl;
	std::cout << std::endl;

}

void CompareTwoNumbers() {
	const int rand1{ rand() % 11 };
	const int rand2{ rand() % 11 };

	std::cout << "-- Compare 2 numbers -- \n";

	std::cout << "First number is " << rand1 << std::endl;
	std::cout << "Second number is " << rand2 << std::endl;
	if (rand1 > rand2)
		std::cout << "First number is larger than the second one" << std::endl;
	else if (rand1 < rand2)
		std::cout << "Second number is larger than the first one" << std::endl;
	else
		std::cout << "First and second number are equal" << std::endl;
}

void CalculatePrice() {
	int ballPointsNbr{};
	float price{};
	std::cout << "\n -- Calculate price -- \n";
	std::cout << "Nr of ballpoints? ";
	std::cin >> ballPointsNbr;
	if (ballPointsNbr < 20)
		price = 4.f;
	else if (ballPointsNbr < 50)
		price = 3.5f;
	else if (ballPointsNbr <= 100)
		price = 3.25f;
	else
		price = 3.51f;
	std::cout << "Total price is  " << ballPointsNbr * price << std::endl;
}

void ConvertDayNumber() {
	int day{};

	std::cout << "\n -- Convert day number -- \n";
	std::cout << "Day number [1, 7] ? ";
	std::cin >> day;
	if (day == 1)
		std::cout << "Start of the week \n";
	else if (day < 5)
		std::cout << "Middle of the week \n";
	else if (day == 5)
		std::cout << "Nearly weekend \n";
	else if (day < 8)
		std::cout << "weekend \n";
	else
		std::cout << "Wrong day number \n";

	switch (day)
	{
	case 1:
		std::cout << "Monday\n";
		break;
	case 2:
		std::cout << "Tuesday\n";
		break;
	case 3:
		std::cout << "Wednesday\n";
		break;
	case 4:
		std::cout << "Thursday\n";
		break;
	case 5:
		std::cout << "Friday\n";
		break;
	case 6:
		std::cout << "Saturday\n";
		break;
	case 7:
		std::cout << "Sunday\n";
		break;
	default:
		break;
	}
}

void CheckLeapYear() {
	int year{};
	int result{};
	std::cout << "\n -- Check leap year -- \n";
	std::cout << "Year ? ";
	std::cin >> year;

	if (year % 4 != 0)
		result = 28;
	else if (year % 100 != 0)
		result = 29;
	else if (year % 400 != 0)
		result = 28;
	else
		result = 29;

	std::cout << year << ": " << result << std::endl;
}

void ConvertSeconds() {
	int seconds{};
	std::cout << "\n -- Convert seconds -- \n";
	std::cout << "Number of seconds ? ";
	std::cin >> seconds;

	std::cout << seconds / 60 / 60 / 24 << " days" << std::endl;
	std::cout << seconds / 60 / 60 % 24 << " hours" << std::endl;
	std::cout << seconds / 60 % 60 << " minutes" << std::endl;
	std::cout << seconds % 60 << " seconds" << std::endl;
}

void DefineUseActorState() {

	enum class ActorState
	{
		running,
		flying,
		falling
	};

	ActorState actorState{ ActorState((rand() % 3)) };

	std::cout << "\n -- Define and Use ActorState -- \n";

	switch (actorState)
	{
	case ActorState::running:
		std::cout << "running \n";
		break;
	case ActorState::flying:
		std::cout << "flying \n";
		break;
	case ActorState::falling:
		std::cout << "falling\n";
		break;
	default:
		break;
	}
}

void DefineUsePoint2f() {
	struct Point2f {
		float x;
		float y;
	};

	Point2f p1;
	Point2f p2{};
	Point2f p3{ 26,25 };

	std::cout << "\n -- Define and Use Point2f -- \n";

	//std::cout << "p1: [" << p1.x << ", " << p1.y << "]" << std::endl;
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]" << std::endl;
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]" << std::endl;

	p1.x = 20;
	p1.y = 3;
	p2 = Point2f{ 30, 40 };
	p3.x++;
	p3.y--;

	std::cout << "Values after changing the members\n";
	std::cout << "p1: [" << p1.x << ", " << p1.y << "]" << std::endl;
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]" << std::endl;
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]" << std::endl;

}

