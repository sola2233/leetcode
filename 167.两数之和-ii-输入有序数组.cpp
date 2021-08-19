/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
/** 
 * 双指针
 * 解题思想：
 * 两个指针反向遍历，左指针l从左往右遍历，右指针r从右往左遍历
 * 如果两个指针指向元素的和小于给定值，左指针右移
 * 如果两个指针指向元素的和大于给定值，右指针左移
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        int sum = 0;
        while(l < r)
        {
            sum = numbers[l] + numbers[r];
            if(sum == target)
                break;
            else if(sum < target)
                ++l;
            else
                --r;
        }
        return vector<int>{l+1, r+1};
    }
};
// @lc code=end

