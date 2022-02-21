/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
/** 
 * 数组题，前缀和 + hash
 * 不能用遍历两遍的方法，只能遍历一遍
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // 前缀和为 0 的有一个
        mp[0] = 1;
        int count = 0, pre_sum = 0;
        for (auto& x : nums)
        {
            // 计算前缀和
            pre_sum += x;
            // pre_sum - k 是我们想找的前缀和
            if (mp.find(pre_sum - k) != mp.end())
                // 如果找到就更新返回值
                count += mp[pre_sum - k];
            // 当前前缀和加入 hashmap 并计数
            ++mp[pre_sum];
        }
        return count;
    }
};
// @lc code=end

