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
	// ������ �� �������
	for (int h = 1; h <= LARGE_SIZE; h = h + 1000) {
		cout << h << ";";
		srand(time(nullptr));
		// �������� ��������� ������
		generate(arr, arr + h, rnd());
		copy(arr, arr + h, arr_copy);
		// ������ �������
		time_t start = clock();
		//  ����������, ��������� ������� qsort
		qsort(arr, h, sizeof(int), comp);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << ";";
		// ��� ������ �������
		start = clock();
		//  ����������, ��������� �������� �++
		sort(arr_copy, arr_copy + h);
		cout << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "\n";
	}
	return 0;
}