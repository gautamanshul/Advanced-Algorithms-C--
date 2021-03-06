// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <utility>

//Quicksort algorithm
//Select the last number as the pivot
class QuickSort {
	std::vector<int> harr;
public:
	QuickSort(std::vector<int> &);
	void qsAlgo(int low, int high);
	void QSPartition(int low, int high, int &position);
	void PrintSortedArray();
};

QuickSort::QuickSort(std::vector<int> & arr) : harr(arr) {}

void QuickSort::QSPartition(int low, int high, int &position)
{
	int moveRight = low;
	int moveLeft = high + 1;
	int x = harr[low];
	while (moveLeft > moveRight) {
		do {
			moveLeft = moveLeft - 1;
		} while (moveLeft >= 0 && !(harr[moveLeft] <= x));

		do {
			moveRight = moveRight + 1;
		} while (moveRight < harr.size() && !(harr[moveRight] >= x));

		if (moveRight < moveLeft) {
			std::swap(harr[moveLeft], harr[moveRight]);
		}
	}

	position = moveLeft;
	harr[low] = harr[position];
	harr[position] = x;
}


void QuickSort::qsAlgo(int low, int high)
{
	int position = 0;
	if (high > low) {
		QSPartition(low, high, position);
		qsAlgo(low, position - 1);
		qsAlgo(position + 1, high);
	}
}

void QuickSort::PrintSortedArray()
{
	for (auto itr = harr.begin(); itr != harr.end(); itr++) {
		std::cout << *itr << " ";
	}

	std::cout << std::endl;
}

int main()
{
	int arr[] = { 23, 9, 23, 52, 15, 19, 47, 67, 107, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> harr(arr, arr + n);

	QuickSort qs(harr);
	qs.qsAlgo(0, n - 1);

	qs.PrintSortedArray();

	return 0;
}

