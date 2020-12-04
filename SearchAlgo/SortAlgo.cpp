#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "basic_method.h"
#include "merge_sort.h"
#include "Heap.h"

int main()
{
    using namespace std;

   /* default_random_engine rnd;
    rnd.seed(10);
    uniform_int_distribution<unsigned> u(0, 100);

    vector<int> vec(20);
    for (int i = 0; i < vec.size();i++) {
        vec[i] = u(rnd);
    } */
    vector<int> vec = { 503, 87, 512, 61,908,170,897,275,653,426 };

    Heap heap;
    heap.sort(vec);
    //Merge mer = Merge(10);
    //select_sort(vec);
    //shell_sort(vec);
    //mer.up_merge_sort(vec, 0, vec.size()-1);
    //mer.down_merge_sort(vec);
    //quick_sort(vec, 0, vec.size() - 1);
    show(vec);
}