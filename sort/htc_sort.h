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
#include <vector>

void quick_sort(std::vector<int> &nums, int l, int r);

void merge_sort(std::vector<int> &nums, int l, int r, std::vector<int> &temp);

void insertion_sort(std::vector<int> &nums);

void bubble_sort(std::vector<int> &nums);

void selection_sort(std::vector<int> &nums);