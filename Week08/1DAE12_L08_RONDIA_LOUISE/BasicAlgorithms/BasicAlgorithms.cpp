// BasicAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Rondia Louise 1DAE12

#include "pch.h"
#include <iostream>

void	PrintElements(const int* pArrayInt, int size);
void	PrintElements(const int* pArrayInt, int startIdx, int endIdx);
int		GetIndex(int rowIdx, int colIdx, int nrCols);
int		GetRow(int index, int nrCols);
int		GetCol(int index, int nrCols);
void	Print2DArr(const int* pArray, int size, int nrCol);

int		Count(int val, const int* pArray, int size);
int		MinElement(const int* pArray, int size);
int		MaxElement(const int* pArray, int size);
void	Swap(int* pArray, int index1, int index2);
void	Shuffle(int* pArray, int size, int amount);
void	BubbleSort(int* pArray, int size);
void	TestCount(int val, const int* pArray, int size);
void	TestMinElement(const int* pArray, int size);
void	TestMaxElement(const int* pArray, int size);
void	TestSwap(int* pArray, int index1, int index2, int size);
void	TestShuffle(int* pArray, int size, int amount);
void	TestBubbleSort(int* pArray, int size);

int main()
{
	srand(int(time(nullptr)));
	const int sizeA{ 10 }, sizeB{ 15 };
	int arrayA[sizeA]{}, arrayB[sizeB]{};
	for (int i{}; i < sizeA; i++) {
		arrayA[i] = rand() % 20 - 10;
	}
	for (int i{}; i < sizeB; i++) {
		arrayB[i] = rand() % 10 - 5;
	}

	TestCount(1, arrayA, sizeA);
	TestCount(-3, arrayB, sizeB);

	TestMinElement(arrayA, sizeA);
	TestMinElement(arrayB, sizeB);

	TestMaxElement(arrayA, sizeA);
	TestMaxElement(arrayB, sizeB);

	TestSwap(arrayA, 0, 3, sizeA);
	TestSwap(arrayB, 1, 2, sizeB);

	TestShuffle(arrayA, sizeA, 1);
	TestShuffle(arrayB, sizeB, 10);

	TestBubbleSort(arrayA, sizeA);
	TestBubbleSort(arrayB, sizeB);

	std::cout << "\n	-- Finally, lets shuffle array A 100 times and sort it again --\n";
	TestShuffle(arrayA, sizeA, 100);
	TestBubbleSort(arrayA, sizeA);
}

int		Count(int val, const int* pArray, int size) {
	int count{};
	for (int i{}; i < size; ++i) {
		if (pArray[i] == val)
			count++;
	}
	return count;
}

int		MinElement(const int* pArray, int size) {
	int min{pArray[0]};

	for (int i{}; i < size; ++i) {
		if (pArray[i] < min)
			min = pArray[i];
	}
	return min;
}

int		MaxElement(const int* pArray, int size) {
	int max{ pArray[0] };

	for (int i{}; i < size; ++i) {
		if (pArray[i] > max)
			max = pArray[i];
	}
	return max;
}

void	Swap(int* pArray, int index1, int index2) {
	int tmp{ pArray[index1] };
	pArray[index1] = pArray[index2];
	pArray[index2] = tmp;
}

void	Shuffle(int* pArray, int size, int amount) {
	for (int i{}; i < amount; ++i) {
		const int index1{ rand() % size };
		int index2{};
		do
		{
			index2 = rand() % size;
		} while (index2 == index1);
		Swap(pArray, index1, index2);
	}
}

void	BubbleSort(int* pArray, int size) {
	int swaps{};
	do
	{
		swaps = 0;
		for (int i{}; i < size - 1; ++i) {
			if (pArray[i + 1] < pArray[i]) {
				Swap(pArray, i, i + 1);
				swaps++;
			}
		}
	} while (swaps);
}


void	TestCount(int val, const int* pArray, int size) {
	std::cout << "\nCounting " << val << " in [ ";
	PrintElements(pArray, size);
	std::cout << "] : " << Count(val, pArray, size) << std::endl;
}

void	TestMinElement(const int* pArray, int size) {
	std::cout << "\nSmallest value in [ ";
	PrintElements(pArray, size);
	std::cout << " ] : " << MinElement(pArray, size) << std::endl;
}

void	TestMaxElement(const int* pArray, int size) {
	std::cout << "\nBiggest value in [ ";
	PrintElements(pArray, size);
	std::cout << " ] : " << MaxElement(pArray, size) << std::endl;
}

void	TestSwap(int* pArray, int index1, int index2, int size) {
	std::cout << "\nSwapping [" << index1 << "] and [" << index2 << "]" << std::endl;
	std::cout << "Before : ";
	PrintElements(pArray, size);

	Swap(pArray, index1, index2);

	std::cout << "\nAfter : ";
	PrintElements(pArray, size);
	std::cout << std::endl;
}

void	TestShuffle(int* pArray, int size, int amount) {
	std::cout << "\nShuffling " << amount << " time(s) 2 random elements" << std::endl;
	std::cout << "Before : ";
	PrintElements(pArray, size);
	
	Shuffle(pArray, size, amount);

	std::cout << "\nAfter : ";
	PrintElements(pArray, size);
	std::cout << std::endl;
}

void	TestBubbleSort(int* pArray, int size) {
	std::cout << "\n-- BubbleSort --" << std::endl;
	std::cout << "Before : ";
	PrintElements(pArray, size);

	BubbleSort(pArray, size);

	std::cout << "\nAfter : ";
	PrintElements(pArray, size);
	std::cout << std::endl;
}

void PrintElements(const int* pArrayInt, int size) {
	for (int i{}; i < size; i++) {
		std::cout << pArrayInt[i] << " ";
	}
}

void PrintElements(const int* pArrayInt, int startIdx, int endIdx) {
	for (int i{ startIdx }; i < endIdx; i++) {
		std::cout << pArrayInt[i] << " ";
	}
}

int GetIndex(int rowIdx, int colIdx, int nrCols) {
	return rowIdx * nrCols + colIdx;
}

int GetRow(int index, int nrCols) {
	return index / nrCols;
}

int GetCol(int index, int nrCols) {
	return index % nrCols;
}

void Print2DArr(const int* pArray, int size, int nrCol) {

	for (int i{}; i < size; i++) {
		std::cout << pArray[i] << "	";
		if (i % nrCol == nrCol - 1 || i == size - 1)
			std::cout << std::endl;
	}
}