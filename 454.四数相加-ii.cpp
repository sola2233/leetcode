/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
/** 
 * hashmap
 * 前两个数组中数字之和的所有可能放到 hashmap 中，value 存放每种可能出现次数
 * 对后两个数组中数字之和 k + l，在 hashmap 中找 -(k + l) 是否存在
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hashmap;
        // 遍历 nums1 nums2
        for (int& i : nums1)
        {
            for (int& j : nums2)
                hashmap[i + j]++;
        }
        // 遍历 nums3 nums4
        int res = 0;
        for (int& k : nums3)
        {
            for (int& l : nums4)
            {
                if (hashmap.count(-(k + l)))
                    res += hashmap[-(k + l)];
            }
        }

        return res;
    }
};
// @lc code=end

