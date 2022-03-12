/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
/** 
 * hash，对每个数 nums[i]，搜索以 nums[i] 为起点的连续数字长度
 * 优化，只有当 nums[i] - 1 不存在时，才会搜索，避免了重复搜索较短的连续数字序列
 */
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 建立hash索引，去重
        unordered_set<int> hashset;
        for (auto& num : nums)
            hashset.insert(num);
        
        // 遍历
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 避免搜索较短序列
            if (hashset.count(nums[i] - 1))
                continue;
            int num = nums[i];
            int len = 1;
            while (hashset.count(num + 1))
            {
                len++;
                num++;
            }
            res = max(res, len);
        }
        return res;
    }
};
// @lc code=end

