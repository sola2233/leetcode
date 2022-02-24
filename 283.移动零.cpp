/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
/** 
 * 数组，快慢指针
 */
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;
        // 快慢指针，先把非 0 元素移动到数组前面
        while (fast < n)
        {
            // [0, slow) 都是非 0 元素
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        // [slow, n) 填充为 0
        while (slow < n)
            nums[slow++] = 0;
    }
};
// @lc code=end

