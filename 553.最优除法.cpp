/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

// @lc code=start
/** 
 * 模拟题，根据数学性质
 * 因为都是正整数，所以分子最大为 num[0]
 * 分母最小为 nums[1] / nums[2] / ... / nums[n - 1]
 * 加一个括号即可
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res;
        int n = nums.size();
        if (n == 1)
        {
            res += to_string(nums[0]);
            return res;
        }
        if (n == 2)
        {
            res += to_string(nums[0]) + "/" + to_string(nums[1]);
            return res;
        }

        // n >= 3 时
        res += to_string(nums[0]) + "/(";
        for (int i = 1; i < n; ++i)
            res += to_string(nums[i]) + "/";
        res.pop_back();
        res.push_back(')');

        return res;
    }
};
// @lc code=end

