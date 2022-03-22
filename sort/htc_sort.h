////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C), 2021, 南京理工大学计算机科学与工程学院, 模式识别与智能系统
//  FileName: sort.h
//  Author: HTC
//  Date: 2021.12.14
//  Description: 几种常用排序
//  Modify: 
//
////////////////////////////////////////////////////////////////////////////////////////////////
// C++标准库
#include <vector>
#include <iostream>
#include <algorithm>    // swap函数

// 快速排序
void quick_sort(std::vector<int> &nums, int l, int r);

// 归并排序
void merge_sort(std::vector<int> &nums, int l, int r, std::vector<int> &temp);

// 插入排序
void insertion_sort(std::vector<int> &nums);

// 希尔排序
void shell_sort(std::vector<int>& nums);

// 冒泡排序
void bubble_sort(std::vector<int> &nums);

// 选择排序
void selection_sort(std::vector<int> &nums);

// 堆排序
void heap_sort(std::vector<int>& nums);
void heap_build(std::vector<int>& nums);
void percolateDown(std::vector<int>& nums, int n, int i);