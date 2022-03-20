/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
/** 
 * 数组+双指针
 * 因为数组有序，相等的元素在数组中的下标一定是连续的
 * 利用数组有序的特点，可以通过双指针的方法删除重复元素。
 */
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;
        // 双指针，把不重复的元素移动到前面去
        while (fast < nums.size())
        {
            if (nums[fast] != nums[slow])
            {
                // [0, slow] 都是不重复的元素
                ++slow;
                nums[slow] = nums[fast];
            }
            ++fast;
        }
        // 数组长度为索引 + 1
        return slow + 1;
    }
};
// @lc code=end

