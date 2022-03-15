#include <algorithm>    // swap函数
#include "htc_sort.h"   // 本项目头文件

/**
 * 快速排序 （采用左闭右开的二分写法）
 * 参考https://www.runoob.com/w3cnote/quick-sort-2.html
 * 快速排序的逻辑是：
 * 若要对 nums[lo..hi] 进行排序，我们先找一个分界点 p，称为 "基准"（key）
 * 通过交换元素使得 nums[lo..p-1] 都小于等于 nums[p]，且 nums[p+1..hi] 都大于 nums[p]
 * 然后递归地去 nums[lo..p-1] 和 nums[p+1..hi] 中寻找新的分界点，最后整个数组就被排序了
 * @param nums 待排序数组
 * @param l 区间左端点
 * @param r 区间右端点
 */
void quick_sort(std::vector<int> &nums, int l, int r)
{
    // base case，最终区间里必须还有一个数
    if (l + 1 >= r)
        return;

    // 首位双指针
    int first = l, last = r - 1;
    // 选取 nums[first] 为基准 key，此时复制 key，一趟排序完会用到
    int key = nums[first];

    while (first < last)
    {
        // 当 nums[last] 比基准大时，不断前移 last
        while (first < last && nums[last] >= key)
            --last;
        // 结束时 nums[last] 小于 key，不直接交换 nums[first] nums[last]
        // 将比 key 小的 nums[last] 直接移到前面
        nums[first] = nums[last];
        // 当 nums[first] 比基准小时，不断后移 first
        while (first < last && nums[first] <= key)
            ++first;
        // 结束时 nums[first] 大于 key，不直接交换 nums[first] nums[last]
        // 将比 key 大的 nums[first] 直接移到后面
        nums[last] = nums[first];
    }
    // 此时 first = last，令它为基准，前面的数都比他小，后面的数都比他大
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}

/**
 * 归并排序 （左闭右开区间） 采用分治法（Divide and Conquer）
 * 参考https://www.runoob.com/w3cnote/merge-sort.html
 * 算法步骤：
 * 1.申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
 * 2.设定两个指针 p和q，最初位置分别为两个已经排序序列的起始位置；
 * 3.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
 * 4.重复步骤 3 直到某一指针达到序列尾；
 * 5.将另一序列剩下的所有元素直接复制到合并序列尾。 
 * @param nums 待排序数组
 * @param l 区间左端点
 * @param r 区间右端点
 * @param temp 大小等同于原数组的额外空间
 */
void merge_sort(std::vector<int>& nums, int lo, int hi, std::vector<int>& temp)
{
    // base case，最终区间里必须还有一个数
    if (lo + 1 >= hi)
        return;

    // 分，递归子数组
    int mid = lo + (hi - lo) / 2;
    merge_sort(nums, lo, mid, temp);
    merge_sort(nums, mid, hi, temp);
    // 治，后序位置合并两个有序子数组
    int p1 = lo;    // 左子序列起始指针
    int p2 = mid;   // 右子序列起始指针
    int i = lo;     // 给 temp 赋值用
    // 两个子序列中，小的数放到前面，相等是为了保证稳定性
    while (p1 < mid && p2 < hi)
        temp[i++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];
    // 下面两个循环只会执行一个
    while (p1 < mid)
        temp[i++] = nums[p1++];
    while (p2 < hi)
        temp[i++] = nums[p2++];
    // 用 temp 中排序好的数组覆盖原数组
    for (i = lo; i < hi; ++i)
        nums[i] = temp[i];
}

/**
 * 插入排序
 * 参考https://www.runoob.com/w3cnote/insertion-sort.html
 * 插入排序是一种最简单直观的排序算法，它的工作原理是通过构建有序序列，
 * 对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 * 算法步骤：
 * 将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
 * 从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。
 * （如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。） 
 * @param nums 待排序数组
 */
void insertion_sort(std::vector<int> &nums)
{
    int n = nums.size();
    // i 遍历过得元素都是已排序完的，从第二个元素开始，第一个元素默认已经排好序
    for (int i = 1; i < n; ++i)
    {
        // j == i 是未排序序列第一个元素，从后向前扫描已排序序列，
        // 将元素j插入到合适位置
        for (int j = i; j > 0 && nums[j] < nums[j-1]; --j)
            std::swap(nums[j], nums[j-1]);
    }
}

/**
 * 冒泡排序
 * 参考https://www.runoob.com/w3cnote/bubble-sort.html
 * 扫描待排序数组 n - 1 次，每次都将前面未排序部分最大的数交换到未排序部分最后
 * n - 1 次扫描后，整个数组有序
 * 优化：
 * 设置一个交换标志，如果一轮扫描中没有交换过，则数组已经有序，提前停止
 * @param nums 待排序数组
 */
void bubble_sort(std::vector<int> &nums)
{
    int n = nums.size();
    bool swapped = false;
    // n个元素扫描 n-1 轮
    for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;
        // 每次扫描将大的元素移动到最后
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        // 提前结束
        if (!swapped)
            break;
    }
}

/**
 * 选择排序
 * 参考https://www.runoob.com/w3cnote/selection-sort.html
 * 选择排序是一种简单直观的排序算法，无论什么数据进去都是 O(n²) 的时间复杂度。
 * 所以用到它的时候，数据规模越小越好。唯一的好处可能就是不占用额外的内存空间。 
 * 算法步骤：
 * 首先在未排序序列中找到最小元素，存放到排序序列的起始位置。
 * 再从剩余未排序元素中继续寻找最小元素，然后放到已排序序列的末尾。
 * 重复第二步，直到所有元素均排序完毕。
 * @param nums 待排序数组
 */
void selection_sort(std::vector<int> &nums)
{
    int n = nums.size();
    int mid;
    // n 个元素扫描 n-1 遍
    for (int i = 0; i < n - 1; ++i)
    {
        mid = i;
        for (int j = i + 1; j < n; ++j)
        {
            // 在未排序序列中找到最小元素赋值给 mid
            if (nums[j] < nums[mid])
                mid = j;
        }
        std::swap(nums[mid], nums[i]);
    }
}

/**
 * 堆排序 o(nlogn)
 * 对于选择排序，有两种做法，都是 o(n^2) 复杂度：
 * 1.n - 1 趟扫描，每次把最小的元素放到前面
 * 2.n - 1 趟扫描，每次把最大的元素放到后面
 * 堆：
 * n 个节点，root 如果从 0 开始：
 * 父节点: i，左子树: 2 * i + 1，右子树: 2 * i + 2
 * 子节点: i，父节点: (i - 1) / 2
 * 堆排序借鉴第 2 种方法，且可以做到就地排序，不需要额外空间，最后的内部节点就是最后一个节点的父亲
 * 1.原向量建立大顶堆，建堆采用 floyd 建堆算法:从内部节点 (n-2) / 2 开始的下滤，复杂度 O(n)
 * 2.交换堆顶和末尾元素
 * 3.对处在堆顶的末尾元素执行下滤
 */
void heap_sort(std::vector<int>& nums)
{
    int n = nums.size();
    // 建堆
    heap_build(nums);
    // n - 1 趟扫描
    for (int i = 0; i < n - 1; ++i)
    {
        // 交换第一个和最后一个，要用 front，不能用 i
        std::swap(nums.front(), nums[n - i - 1]);
        percolateDown(nums, n - i - 1, 0);
    }
}

/** 建大顶堆 */
void heap_build(std::vector<int>& nums)
{
    int n = nums.size();
    for (int i = (n - 2) / 2; i >= 0; i--)
        percolateDown(nums, n, i);

    for (int i = 0; i < nums.size(); i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
}

/**
 * 下滤，直到叶子节点 
 * @param i 当前节点下标为 i
 * @param n 当前堆的规模，不是 nums 的大小
 */
void percolateDown(std::vector<int>& nums, int n, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2;
    int max_child = i;
    // 分两步比较，找到最大的孩子
    if (left < n && nums[left] > nums[max_child])
        max_child = left;
    if (right < n && nums[right] > nums[max_child])
        max_child = right;
    if (max_child != i)
    {
        std::swap(nums[i], nums[max_child]);
        percolateDown(nums, n, max_child); // 递归
    }
}