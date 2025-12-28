// Rondia, Louise, 1DAE12

#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>

void TestGrowingPains();
void TestReserve();
void TestResize();
void PrintVector(const std::vector<int>& vector);
void PrintVectorWithIndex(const std::vector<int>& vector);
void AddRandomElements(std::vector<int>& vector, int amount);
void RemoveElements(std::vector<int>& vector, int amount);
void IncreaseValues(std::vector<int>& vector);
void DecreaseValues(std::vector<int>& vector);
void Reset(std::vector<int>& vector);
void SimulateGrowingPains();


int main()
{
	std::vector<int> vector;

	//TestGrowingPains();
	//TestReserve();
	//TestResize();
	//AddRandomElements(vector, 10);
	//RemoveElements(vector, 6);
	//IncreaseValues(vector);
	//DecreaseValues(vector);
	//Reset(vector);
	SimulateGrowingPains();
}

void TestGrowingPains() {
	std::vector<int> v;
	size_t capacity{ v.capacity() };

	std::cout << "VECTOR:\n=======\n";

	for (int i{}; i < 100; ++i) {
		const int r{ rand() % 10 + 1 };
		const size_t newCapacity{ v.capacity() };

		v.push_back(r);
		std::cout << "Adding value " << r << std::endl;
		if (capacity != newCapacity) {
			std::cout << "-> Growing pain! Capacity from " << capacity << " to " << newCapacity << std::endl;
			capacity = newCapacity;
		}
	}
}

void TestReserve() {
	std::vector<int> v;
	v.reserve(50);
	size_t capacity{ v.capacity() };

	std::cout << "VECTOR:\n=======\n";

	for (int i{}; i < 100; ++i) {
		const int r{ rand() % 10 + 1 };
		const size_t newCapacity{ v.capacity() };

		v.push_back(r);
		std::cout << "Adding value " << r << std::endl;
		if (capacity != newCapacity) {
			std::cout << "-> Growing pain! Capacity from " << capacity << " to " << newCapacity << std::endl;
			capacity = newCapacity;
		}
	}
}

void TestResize() {
	std::vector<int> v;
	v.resize(50);

	size_t capacity{ v.capacity() };
	std::cout << "-> Beginning: capacity at " << capacity << std::endl;

	std::cout << "VECTOR:\n=======\n";

	for (int i{}; i < 100; ++i) {
		const int r{ rand() % 10 + 1 };
		const size_t newCapacity{ v.capacity() };

		if (i < v.size()) v[i] = r;
		else v.push_back(r);
		std::cout << "Adding value " << r << std::endl;
		if (capacity != newCapacity) {
			std::cout << "-> Growing pain! Capacity from " << capacity << " to " << newCapacity << std::endl;
			capacity = newCapacity;
		}
	}
	//PrintVector(v);
	PrintVectorWithIndex(v);
}

void PrintVector(const std::vector<int>& vector) {
	std::cout << "[ ";
	for (const int v : vector) {
		std::cout << v << ", ";
	}
	std::cout << "] -> Size: " << vector.size() << ", capacity: " << vector.capacity() << std::endl;

	//std::for_each(vector.begin(), vector.end(), [](int v) { std::cout << v << ", "; });
}

void PrintIntArray(const int *array, size_t size) {
	std::cout << "Final elements: ";
	for (size_t i{}; i < size; ++i) {
		std::cout << array[i] << ", ";
	}
}

void PrintVectorWithIndex(const std::vector<int>& vector) {
	for (int i{}; i < vector.size(); ++i) {
		std::cout << "[" << i << "] " << vector[i] << "  ";
	}
	std::cout << std::endl;
}

void AddRandomElements(std::vector<int>& vector, int amount) {
	for (int i{}; i < amount; ++i) {
		vector.push_back(rand() % 100 + 1);
	}
	std::cout << "Added " << amount << " elements.\n";
	PrintVector(vector);
}

void RemoveElements(std::vector<int>& vector, int amount) {
	for (int i{}; i < amount; ++i) {
		vector.pop_back();
	}
	std::cout << "Removed " << amount << " elements.\n";
	PrintVector(vector);
}

void IncreaseValues(std::vector<int>& vector) {
	for (int i{}; i < vector.size(); ++i) {
		++vector[i];
	}
	PrintVector(vector);
}

void DecreaseValues(std::vector<int>& vector) {
	for (int i{}; i < vector.size(); ++i) {
		--vector[i];
	}
	PrintVector(vector);
}

void Reset(std::vector<int>& vector) {
	vector.clear();
	std::cout << "Cleared all elements.\n";
	PrintVector(vector);
}

static size_t Reallocate(int*& array, size_t capacity) {
	size_t newCapacity{ 1 };

	if (capacity == 1)
		newCapacity = 2;
	else if (capacity > 1)
		newCapacity = capacity + capacity / 2;

	int* temp = new int[newCapacity];
	for (size_t i{}; i < capacity; ++i) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;

	std::cout << " -> Growing pain! Capacity from " << capacity << " to " << newCapacity << std::endl;
	return newCapacity;
}

void SimulateGrowingPains() {
	std::cout << "SIMULATION:\n===========\n";

	int* array = nullptr;
	size_t size{}, capacity{};

	for (int i{}; i < 100; ++i) {
		const int num{ rand() % 100 + 1 };
		++size;
		if (size > capacity) {
			std::cout << "Adding value " << num;
			capacity = Reallocate(array, capacity);
		}
		array[i] = num;
	}
	PrintIntArray(array, size);
	
}