#include <cstdio>
#include <iostream>
#include "htc_sort.h"

using namespace std;

int main()
{
    //-------------------------------Step1.构建数组-------------------------------//
    vector<int> vec = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};

    for (auto a : vec)
        cout << a << ' ';
    cout << endl;

    int size = vec.size();
    vector<int> temp;
    temp.resize(size);

    //-------------------------------Step2.排序-------------------------------//
    // quick_sort(vec, 0, size);
    merge_sort(vec, 0, size, temp);
    // insertion_sort(vec);
    // bubble_sort(vec);
    // selection_sort(vec);

    //-------------------------------Step3.输出-------------------------------//
    for (auto a : vec)
        cout << a << ' ';
    cout << endl;

    return 0;    
}