#pragma once
#include <iostream>
#include <vector>

class Heap
{
private:
	std::vector<int> heap;
	int capacity, size;
	void filterDown(int start, int end);
	void swap(int i, int j);
public:
	int getMin();
	void sort(std::vector<int>& a);
	void create(std::vector<int>& a);
	void destroy();
};

