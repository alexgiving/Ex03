#include "task1.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t LARGE_SIZE = 500000;

struct rnd {
	int operator()() {
		return rand() % LARGE_SIZE;
	}
};

int main() {
	int arr[LARGE_SIZE];
	int arr_copy[LARGE_SIZE];
	// Рандом по таймеру
	for (int h = 1; h <= LARGE_SIZE; h = h + 1000) {
		cout << h << ";";
		srand(time(nullptr));
		// создание случайных данных
		generate(arr, arr + h, rnd());
		copy(arr, arr + h, arr_copy);
		// отсчет времени
		time_t start = clock();
		//  сортировка, используя функцию qsort
		qsort(arr, h, sizeof(int), comp);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ";";
		// еще отсчет времени
		start = clock();
		//  сортировка, используя алгоритм С++
		sort(arr_copy, arr_copy + h);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	return 0;
}