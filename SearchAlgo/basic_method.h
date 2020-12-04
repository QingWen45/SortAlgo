#pragma once
#include <vector>
#include "Counter.h"
#include <iostream>


void select_sort(std::vector<int>& vec);
void insert_sort(std::vector<int>& vec);
void bubble_sort(std::vector<int>& vec);
void shell_sort(std::vector<int>& vec);

int partition(std::vector<int>& vec, int lo, int hi);
void quick_sort(std::vector<int>& vec, int lo, int hi);

void show(std::vector<int>& vec);
bool is_sorted(std::vector<int>& vec);

template<typename T>
void swap_vec(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}