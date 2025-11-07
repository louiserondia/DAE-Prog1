// Rondia, Louise, 1DAE12

#include <iostream>

int main()
{
	// Read group
	std::cout << "Group? ";
	std::string group{};
	std::cin >> group;
	std::cout << "You're in " << group << std::endl;


	// Celsius to fahrenheit
	std::cout << "Fahrenheit? ";
	float fahrenheit{};
	std::cin >> fahrenheit;
	float celsius{ 5.f / 9.f * (fahrenheit - 32.f) };
	std::cout << "Celsius: " << celsius << std::endl;

	// degrees to radians
	std::cout << "Angle in degrees? ";
	float angle{};
	std::cin >> angle;
	float radians{ angle / 180 * 3.1415f };
	std::cout << "Radians: " << radians << std::endl;

	// Bicycle has speed of 20 km/h, where is it after 2 hours
	int speed{ 20 };
	int hours{ 2 };
	std::cout << "Speed of cyclist is " << speed << " km/h\n";
	std::cout << "After " << hours << " hours the cyclist is " << speed * hours << " km far\n";

	std::cout << "Press ENTER to quit";
	std::cin.ignore(1);
	std::cin.get();
	return 0;
}
