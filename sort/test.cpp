#include <cstdio>
#include <iostream>
#include <queue>
#include "htc_sort.h"

using namespace std;

int main()
{
    //-------------------------------Step1.构建数组-------------------------------//
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};

    for (auto a : nums)
        cout << a << ' ';
    cout << endl;

    int size = nums.size();
    vector<int> temp;
    temp.resize(size);

    //-------------------------------Step2.排序-------------------------------//
    // quick_sort(nums, 0, size);
    merge_sort(nums, 0, size, temp);
    // insertion_sort(nums);
    // bubble_sort(nums);
    // selection_sort(nums);
    // heap_sort(nums);
    // 标准库堆排序
    // make_heap(nums.begin(), nums.end());
    // sort_heap(nums.begin(), nums.end());
    //-------------------------------Step3.输出-------------------------------//
    for (auto a : nums)
        cout << a << ' ';
    cout << endl;

    return 0;    
}