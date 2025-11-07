// Louise Rondia 1DAE12

#include <iostream>
#include "ExploreStructs.h"

int main()
{
	srand(int(time(nullptr)));
	Point2f pos{ rand() % 90 + 10, rand() % 180 + 20 };
	Point2f movement{};

	std::cout << "The initial position(x, y) is: " << pos.x << ", " << pos.y << std::endl;
	std::cout << "What movement do you want in the x direction? ";
	std::cin >> movement.x;
	std::cout << "What movement do you want in the y direction? ";
	std::cin >> movement.y;
	pos.x += movement.x;
	pos.y += movement.y;
	std::cout << "The position after movement (x, y) is: " << pos.x << ", " << pos.y << std::endl;

	PrintBestSellingVideoGame();
}

void PrintBestSellingVideoGame() {
	GameSale bestSelling{};
	bestSelling.title = "Minecraft";
	bestSelling.sales = 238000000;
	bestSelling.series = "Minecraft";
	
	GameSale secondBest{};
	secondBest.title = "Grand Theft Auto V";
	secondBest.sales = 185000000;
	secondBest.series = "Grand Theft Auto";

	GameSale thirdBest{};
	thirdBest.title = "Tetris (EA)";
	thirdBest.sales = 1000000000;
	thirdBest.series = "Tetris";

	std::cout << "\n#1 best selling game: " << bestSelling.title << " (" << bestSelling.series << ") with " << bestSelling.sales << " sales." << std::endl;
	std::cout << "#2 best selling game: " << secondBest.title << " (" << secondBest.series << ") with " << secondBest.sales << " sales." << std::endl;
	std::cout << "#3 best selling game: " << thirdBest.title << " (" << thirdBest.series << ") with " << thirdBest.sales << " sales." << std::endl;
}