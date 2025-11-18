// BasicAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Rondia Louise 1DAE12

#include "pch.h"
#include <iostream>

int		Count(const int *pArray, int size);
int		MinElement(const int *pArray, int size);
int		MaxElement(const int *pArray, int size);
void	Swap(int* pArray, int index1, int index2);
void	Shuffle(int* pArray);
void	BubbleSort(int* pArray);
int		TestCount(const int *pArray, int size);
int		TestMinElement(const int *pArray, int size);
int		TestMaxElement(const int *pArray, int size);
void	TestSwap(int* pArray, int index1, int index2);
void	TestShuffle(int* pArray);
void	TestBubbleSort(int* pArray);

int main()
{
	const int sizeA{ 10 }, sizeB{ 15 };
	int arrayA[sizeA]{}, arrayB[sizeB]{};
	for (int i{}; i < sizeA; i++) {
		arrayA[i] = 1;
	}

}

