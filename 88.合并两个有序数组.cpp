/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
/** 
 * 双指针可以引申到多个数组多个指针
 * 解题思想：
 * 两个指针m和n分别指向两个数组尾
 * 比较m和n指向的数，选择较大的数放到nums1的末尾，因此需要第三个定位指针pos
 * 每次移动m或n，pos也要移动
 * 注意边界：
 * 如果nums1的数字已经复制完，要继续把nums2的数字继续复制
 * 如果nums2的数字已经复制完，剩余nums1的数字不需要再改变
 */
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /** 
         * 插入的位置，nums1数组尾
         * 直接用m和n当作双指针
         */
        int pos = (m--) + (n--) - 1;
        /** 注意边界条件，下标从0开始，所以指针可以等于0 */
        while(m >= 0 && n >= 0)
        {
            /** 复制较大的数到nums1的末尾 */
            nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        /** 继续复制nums2的数 */
        while(n >= 0)
        {
            nums1[pos--] = nums2[n--];
        }
    }
};
// @lc code=end

