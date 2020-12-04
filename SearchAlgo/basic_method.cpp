#include "basic_method.h"
#include <vector>
#include <iostream>

void select_sort(std::vector<int>& vec) {
	int min;
	for (int i = 0; i < vec.size(); i++) {
		min = i;
		for (int j = i+1; j < vec.size(); j++) {
			if (vec[j] < vec[min])
				min = j;
		}
		swap_vec(vec[i], vec[min]);
	}
}

void insert_sort(std::vector<int>& vec) {
	int N = vec.size();
	for (int i = 1; i < N; i++) {
		for (int j = i; j > 0 && (vec[j] < vec[j - 1]); j--) {
			swap_vec(vec[j], vec[j - 1]);
		}
	}
}

void bubble_sort(std::vector<int>& vec) {
	bool madeSwap;
	do{
		madeSwap = false;
		for (int i = 0; i < vec.size()-1; i++){
			if (vec[i] > vec[i + 1]){
				swap_vec(vec[i], vec[i + 1]);
				madeSwap = true;
			}
		}
	} while (madeSwap);
}

void shell_sort(std::vector<int>& vec) {
	int N = vec.size();
	int h = 1;
	while (h < N / 3)
		h = 3 * h + 1;
	while (h >= 1) {
		for (int i = h; i < N; i++) {
			show(vec);
			for (int j = i; j >= h && (vec[j] < vec[j - h]); j -= h) {
				swap_vec(vec[j], vec[j - h]);
			}
		}
		h = h / 3;
	}
	show(vec);
}

int partition(std::vector<int>& vec, int lo, int hi) {
	int i = lo, j = hi + 1;
	int v = vec[lo];
	while (true) {
		while (vec[++i] < v)
			if (i == hi) break;
		while (v < vec[--j])
			if (j == lo) break;
		if (i >= j)
			break;
		swap_vec(vec[i], vec[j]);
	}
	swap_vec(vec[lo], vec[j]);
	return j;
}

void quick_sort(std::vector<int>& vec, int lo, int hi) {
	if (lo >= hi) return;
	int j = partition(vec, lo, hi);
	show(vec);
	quick_sort(vec, lo, j - 1);
	quick_sort(vec, j + 1, hi);
}

void show(std::vector<int>& vec) {
	for (auto i : vec)
		std::cout << i << ' ';
	std::cout << std::endl;
}

bool is_sorted(std::vector<int>& vec) {
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] < vec[i - 1])
			return false;
	}
	return true;
}