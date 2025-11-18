// Rondia Louise 1DAE12
#include "pch.h"
#include <iostream>

void DefineArrays();
void PrintMemoryLocation();
void PrintElements(int* pArrayInt, int size);
void PrintElements(int* pArrayInt, int startIdx, int endIdx);
int GetIndex(int rowIdx, int colIdx, int nrCols);
int GetRow(int index, int nrCols);
int GetCol(int index, int nrCols);
void Print2DArr(int* pArray, int size, int nrCol);
void TestPrint2DArr();


int main()
{
	DefineArrays();
	PrintMemoryLocation();
	TestPrint2DArr();

}

void DefineArrays()
{
	const int size{ 5 };
	int defaultArray[size]{};
	int arr1[]{ 5, 10, 15, 0, 0 };
	int arr2[size]{ 5, 10, 15 };

	std::cout << "-- Accessing elements --" << std::endl;
	std::cout << "First element: " << arr2[0] << std::endl;
	std::cout << "Last element: " << arr2[4] << std::endl << std::endl;
	std::cout << "Iterating over the elements and then going too far :" << std::endl;

	PrintElements(arr1, size);
	PrintElements(arr1, size + 5 ); // too far

	std::cout << "After incrementing the values" << std::endl;
	for (int index{ 0 }; index < size; ++index)
	{
		std::cout << ++arr1[index] << " ";
	}
	std::cout << std::endl;
	PrintElements(arr1, size + 1);

	std::cout << "\n	-- Size of arrays --" << std::endl;
	std::cout << "	2nd array" << std::endl;
	std::cout << "	nr of bytes: " << sizeof(arr1) << std::endl;
	std::cout << "	size of one element: " << sizeof(arr1[1]) << std::endl;
	std::cout << "	nr of elements: " << sizeof(arr1) / sizeof(arr1[0]) << std::endl << std::endl;

	const int arrSize{ sizeof(arr1) / sizeof(arr1[0]) };
	PrintElements(arr1, arrSize);

	std::cout << "print range of array: \n";
	PrintElements(arr1, 2, size);
}

void PrintMemoryLocation() {
	struct Point2f {
		float x;
		float y;
	};

	const int size{ 5 };
	int arrInt[size]{};
	Point2f arrPoint2f[size]{};

	std::cout << "\nThe elements occupy consecutive memory location" << std::endl;
	std::cout << "Array of type int " << std::endl;
	for (int i{}; i < size; i++) {
		std::cout << "address of element " << i << " : " << &arrInt[i] << std::endl;
	}

	std::cout << "\nArray of type Point2f " << std::endl;
	for (int i{}; i < size; i++) {
		std::cout << "address of element " << i << " : " << &arrPoint2f[i] << std::endl;
	}

}

void PrintElements(int* pArrayInt, int size) {
	for (int i{}; i < size; i++) {
		std::cout << pArrayInt[i] << " ";
	}
	std::cout << std::endl;
}

void PrintElements(int* pArrayInt, int startIdx, int endIdx) {
	for (int i{startIdx}; i < endIdx; i++) {
		std::cout << pArrayInt[i] << " ";
	}
	std::cout << std::endl;
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

void TestPrint2DArr() {
	std::cout << std::endl;
	int arr[20]{};
	for (int i{}; i < 20; i++) {
		arr[i] = i + 1;
	}
	std::cout << "	-- 2D visualization of 1D array --\n";
	Print2DArr(arr, 20, 5);
}

void Print2DArr(int* pArray, int size, int nrCol) {

	for (int i{}; i < size; i++) {
		std::cout << pArray[i] << "	";
		if (i % nrCol == nrCol - 1 || i == size - 1)
			std::cout << std::endl;
	}
}