#include "Heap.h"

void Heap::filterDown(int start, int end) {
    int c = start;
    int l = 2 * c + 1; //left child
    int temp = heap[c];
    while (l <= end) {
        if (l < end && heap[l] > heap[l + 1])
            l++;
        if (temp <= heap[l])
            break;
        else {
            heap[c] = heap[l];
            c = l;
            l = 2 * l + 1;
        }
    }
    heap[c] = temp;
}

void Heap::swap(int i, int j) {
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

int Heap::getMin() {
    if (size == 0)
        return NULL;
    int n;
    n = heap[0];
    swap(0, size - 1);
    filterDown(0, size - 2);
    size--;
    return n;
}

void Heap::create(std::vector<int>& a) {
    int i;
    size = a.size();
    capacity = size;
    heap.resize(size);
    for (i = 0; i < size; i++)
        heap[i] = a[i];
    for (i = size / 2 - 1; i >= 0; i--)
        filterDown(i, size - 1);
}

void Heap::sort(std::vector<int>& a) {
    create(a);
    a.clear();
    for (int i = 0; i < capacity; i++)
        a.push_back(getMin());
    destroy();
}

void Heap::destroy() {
    size = 0; capacity = 0;
    heap.clear();
}