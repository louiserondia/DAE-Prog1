#include <iostream>
#include <ctime>
#include <string> 

#pragma region Function declarations

// Function declarations
void DetermineSkill();
void GetColorCodes();
void Wait();

#pragma endregion Function declarations


int main()
{
	std::cout << "== ErrorSolving - name, firstname - 1DAExx ==\n";
	// rand seed
	srand(unsigned int(time(nullptr)));

	DetermineSkill();
	GetColorCodes();
	Wait();
}

#pragma region Function definitions
// Function definitions
void GetColorCodes()
{
	enum class ColorMenuChoice
	{
		cyan,
		stop,
		yellow,
		magenta
	};

	std::cout << "\n-- GetColorCodes function --\n";

	std::string menu{ "\nMake your choice\n" 
		+ std::to_string(int(ColorMenuChoice::stop))
		+ ".Stop\n"
		+ std::to_string(int(ColorMenuChoice::magenta))
		+ ".Magenta\n" 
		+ std::to_string(int(ColorMenuChoice::yellow))
		+ ".Yellow\n"
		+ std::to_string(int(ColorMenuChoice::cyan))
		+ ".Cyan\n ? " };

	bool quit{ false };
	int	choice{};
	std::cout << menu;
	std::cin >> choice;
	switch (ColorMenuChoice(choice))
	{
	case ColorMenuChoice::stop:
		break;
	case ColorMenuChoice::magenta:
		std::cout << "Magenta 0xFF00FF\n";
		break;
	case ColorMenuChoice::yellow:
		std::cout << "Yellow 0xFFFF00\n";
		break;
	case ColorMenuChoice::cyan:
		std::cout << "Cyan 0x00FFFF\n";
		break;
	default:
		std::cout << "Wrong choice\n";
		break;
	}

	std::cin.ignore();
}


void DetermineSkill()
{
	std::cout << "\n-- Determine Skill function --\n";

	int years{};
	std::cout << "Your years of experience ? ";
	std::cin >> years;
	std::string level{};
	if (years < 5)
	{
		level = "Junior level";
	}
	else if (years < 10)
	{
		level = "Intermediate level";
	}
	else
	{
		level = "Senior level";
	}
	std::cout << level << std::endl;

	std::cin.ignore();
}

void Wait()
{
	std::cout << "Press ENTER to quit";
	std::cin.get();
}