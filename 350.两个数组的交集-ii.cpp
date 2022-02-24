/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> hashmap;
        // 计数
        for (int& num : nums1)
            hashmap[num]++;
        // 遍历 nums2
        for (int& num : nums2)
        {
            // 找两个集合交集
            if (hashmap.count(num))
            {
                // 每个元素出现次数选择较小值
                if (hashmap[num] > 0)
                {
                    res.push_back(num);
                    hashmap[num]--;
                }
            }
        }

        return res;
    }
};
// @lc code=end

