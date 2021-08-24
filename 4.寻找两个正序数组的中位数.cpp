/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
/** 
 * 二分查找，时间复杂度O(log(m+n))
 * step1.首先分情况计算k
 * 两个升序数组长度分别为m、n，总长度为size = m + n
 * 如果size为奇数，要找第k = (size + 1) / 2小的数，下标从1开始
 * 如果size为偶数，要找第k = size / 2小的数和第k + 1小的数，计算它们的平均
 * step2.二分查找第k小的数
 * l为左端点，mid = l + k / 2 - 1
 * 在两个数组中区间[l, mid]中循环查找
 * 每次比较nums1[mid]和nums2[mid]，丢弃较小的区间
 * 令较小区间的l = mid + 1，k也要减去被丢弃的区间大小(不能直接减k/2)，k -= mid - l + 1
 * step3.三种特殊情况要考虑
 * 1.nums1[k/2−1]或者nums2[k/2−1]越界，可以选取对应数组中的最后一个元素m - 1或n - 1
 *   在这种情况下，我们必须根据排除数的个数减少k的值，而不能直接将k减去 k/2。
 * 2.如果一个数组左端点l等于数组大小，即l == m或n，说明该数组中的所有元素都被排除，
 *   直接返回另一个数组中第k的元素。
 * 3.终止条件，k==1时，返回两个数组首元素最小值
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /** 二分查找 */
        int size = nums1.size() + nums2.size();
        /** 奇数时 */
        if (size % 2 == 1)
        {
            return getKthElement(nums1, nums2, (size + 1) / 2);
        }
        /** 偶数时 */
        else
        {
            double pivot = (getKthElement(nums1, nums2, size / 2) 
                        + getKthElement(nums1, nums2, size / 2 + 1)) / 2.0;
            return pivot;
        }
    }

    /**
     * 寻找第k小的数 
     * @param k 要找的第k小的数，下标的话需要减一
     */
    int getKthElement(vector<int>& nums1, vector<int>&nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        /** nums1和nums2的首指针位置，每次循环需要加上被删掉的数 */
        int l1 = 0, l2 = 0;
        while (true)
        {
            /** l超过nums1的大小 */
            if (l1 == m)
            {
                return nums2[l2 + k - 1];
            }
            /** l超过nums2的大小 */
            if (l2 == n)
            {
                return nums1[l1 + k - 1];
            }
            /** 结束条件，k已经减小到1 */
            if (k == 1)
            {
                /** 返回nums1 nums2数组头小的那个 */
                return min(nums1[l1], nums2[l2]);
            }
            /** 一般情况 */
            int mid1 = min(l1 + k / 2 - 1, m - 1);
            int mid2 = min(l2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[mid1];
            int pivot2 = nums2[mid2];
            if (pivot1 <= pivot2)
            {
                /** 计算nums1中被丢弃的部分有多少个数 */
                k -= mid1 - l1 + 1;
                l1 = mid1 + 1;
            }
            else
            {
                /** 计算nums2中被丢弃的部分有多少个数 */
                k -= mid2 - l2 + 1;
                l2 = mid2 + 1;
            }
        }
    }
};
// @lc code=end

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     /** 双指针 */
//     int m = nums1.size();
//     int n = nums2.size();
//     vector<int> num(m+n, 0);
//     int i = m + n - 1;
//     --m; 
//     --n;
//     for (; m >= 0 && n >= 0; --i)
//     {
//         if (nums1[m] >= nums2[n])
//         {
//             num[i] = nums1[m--];
//         }
//         else
//         {
//             num[i] = nums2[n--];
//         }
//     }
//     while (m >= 0)
//     {
//         num[i--] = nums1[m--];
//     }
//     while (n >= 0)
//     {
//         num[i--] = nums2[n--];
//     }
//     int mid = (nums1.size() + nums2.size() - 1) / 2;
//     return (nums1.size() + nums2.size())%2 == 0 ? (num[mid] + num[mid + 1]) / 2.0 : num[mid];
// }