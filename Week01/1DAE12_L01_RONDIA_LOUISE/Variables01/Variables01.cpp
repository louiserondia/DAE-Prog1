// Rondia, Louise, 1DAE12

#include <iostream>

int main()
{
    /*
    int numberOfCats;
    char initial;
    bool isEating;
    float size;
    double positionX;
    */

    /*
    int numberOfCats{};
    char initial{};
    bool isEating{};
    float size{};
    double positionX{};
    */


    int numberOfCats{ 1 };
    char initial{ 'P' };
    bool isEating{ 0 };
    float size{ 33.3f };
    double positionX{ 27.83 };

    numberOfCats = 2;
    initial = 'C';
    isEating = true;
    size = 27.8f;
    positionX = 4.99;


    std::cout << "There is/are " << numberOfCats << " cat(s) in the room.\n";
    std::cout << "Cat[0]'s initial is : " << initial << std::endl;
    std::cout << "Is the cat eating ? " << isEating << std::endl;
    std::cout << "Cat[0]'s size is " << size;
    std::cout << "cm and its x position is " << positionX << ".\n";


    std::cout << "Please choose how many cats you want -> ";
    std::cin >> numberOfCats;
    std::cout << "Please type cat[0]'s initial -> ";
    std::cin >> initial;
    std::cout << "Please choose if the cat's eating -> ";
    std::cin >> isEating;
    std::cout << "Please choose its size -> ";
    std::cin >> size;
    std::cout << "Please choose its x position -> ";
    std::cin >> positionX;

    std::cout << "There are now " << numberOfCats << " in the room.\n";
    std::cout << "Cat[0]'s initial is : " << initial << std::endl;
    std::cout << "Is the cat eating ? " << isEating << std::endl;
    std::cout << "Cat[0]'s size is " << size;
    std::cout << "cm and its x position is " << positionX << ".\n";

}
