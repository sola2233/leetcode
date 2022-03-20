/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
/** 
 * 数组，双指针
 */
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {
            // 只要 nums[fast] 不等于 val，就移动到数组前面
            if (nums[fast] != val)
            {
                // [0, slow) 里的元素都不等于 val
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        // slow 就是新数组长度
        return slow;
    }
};
// @lc code=end

