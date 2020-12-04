#include "merge_sort.h"

void Merge::merge(std::vector<int>& vec, int lo, int mid, int hi) {
	int i = lo, j = mid + 1;

	for (int k = lo; k <= hi; k++)
		aux[k] = vec[k];

	for (int k = lo; k <= hi; k++) {
		if (i > mid)
			vec[k] = aux[j++];
		else if (j > hi)
			vec[k] = aux[i++];
		else if (aux[j] < aux[i])
			vec[k] = aux[j++];
		else
			vec[k] = aux[i++];
	}
}

Merge::Merge(int size) {
	aux.resize(size);
}

void Merge::up_merge_sort(std::vector<int>& vec, int lo, int hi) {
	//show(vec);
	if (hi <= lo)
		return;
	int mid = lo + (hi - lo) / 2;
	Merge::up_merge_sort(vec, lo, mid);
	Merge::up_merge_sort(vec, mid + 1, hi);
	Merge::merge(vec, lo, mid, hi);
}

void Merge::down_merge_sort(std::vector<int>& vec) {
	int N = vec.size();
	for (int sz = 1; sz < N; sz = sz + sz) {
		show(vec);
		for (int lo = 0; lo < N - sz; lo += sz + sz)
			Merge::merge(vec, lo, lo + sz - 1, std::min(lo + sz + sz - 1, N - 1));
	}
	show(vec);
}