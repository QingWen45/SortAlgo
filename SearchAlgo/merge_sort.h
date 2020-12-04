#pragma once
#include <vector>
#include <algorithm>
#include "basic_method.h"


class Merge {
private:
	std::vector<int> aux;
	void merge(std::vector<int>& vec, int lo, int mid, int hi);
public:
	Merge(int size);
	void up_merge_sort(std::vector<int>& vec, int lo, int hi);
	void down_merge_sort(std::vector<int>& vec);
};

