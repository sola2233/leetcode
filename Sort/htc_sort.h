/** 
 * 几种常用排序
 * [稳定性分析](https://www.cnblogs.com/remixnameless/p/13334131.html)
 */
// C++标准库
#include <vector>
#include <iostream>
#include <algorithm>    // swap函数

/** 
 * 快速排序：不稳定
 * 快速排序先排基准 key 的位置，有两个指针，右指针向左走，左指针向右走
 * 在两个指针和基准交换的时候，可能会打乱元素稳定性，比如
 * 5 3 3 4 3 8 9
 */
void quick_sort(std::vector<int> &nums, int l, int r);

/** 
 * 归并排序：稳定
 * 归并排序先分成两个序列，再合并，合并过程中，如果两个元素相等
 * 可以把处于前边序列的元素保存到结果序列的前面，保证了稳定性
 */
void merge_sort(std::vector<int> &nums, int l, int r, std::vector<int> &temp);

/** 
 * 插入排序：稳定
 * 插入排序保存一个已排序部分和待排序部分，每次把待排序的第一个元素插入到已排序部分的合适位置
 * 相等元素插入到后面，保证了稳定性
 */
void insertion_sort(std::vector<int> &nums);

/** 
 * 希尔排序：不稳定
 * 希尔排序按不同步长对元素进行插入排序，一次插入排序是稳定的，
 * 但是相同的元素可能在各自的插入排序中移动，所以不稳定
 */
void shell_sort(std::vector<int>& nums);

/** 
 * 冒泡排序：稳定
 * 冒泡排序每一轮把大的元素两两交换到最后，因为是两两交换，所以如果两个元素相等，可以不交换位置，
 * 从而保证了稳定性
 */
void bubble_sort(std::vector<int> &nums);

/** 
 * 选择排序：不稳定
 * 选择排序每一轮选择最大的元素到最后，前面和后面的元素交换可能会改变稳定性，比如 8 2 1 7 1
 */
void selection_sort(std::vector<int> &nums);

/** 
 * 堆排序：不稳定
 * 堆排序先建立大顶堆，建堆时从 (n-2)/2 开始进行下滤，可能把后面相等的元素交换到前面
 * 但是 (n-2)/2 - 1、(n-2)/2 - 2 可能没有把相同元素交换 
 */
void heap_sort(std::vector<int>& nums);
void heap_build(std::vector<int>& nums);
void percolateDown(std::vector<int>& nums, int n, int i);