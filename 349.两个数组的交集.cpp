/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
/** 
 * hashset
 */
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 存放结果，保证不重复
        unordered_set<int> res;
        unordered_set<int> hashset;
        // 统计数组元素
        for (int& num : nums2)
            hashset.insert(num);
        // 遍历 nums1
        for (int& num : nums1)
        {
            if (hashset.find(num) != hashset.end())
                res.insert(num);
        }

        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

