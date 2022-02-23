/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
/** 
 * 方法1：排序+双指针，其实不行，因为要求返回索引，排序完索引就变了
 * 方法2：hash table。一趟扫描可以解决重复元素的问题，实际上两趟扫描也不会报错，因为题目规定只会有一个解
 *       如果解是重复元素，则第一趟扫描 hashmap 中保存的是靠后的元素，第二趟扫描时因为从前向后扫描，
 *       所以也能找到两个索引值
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        // 一趟扫描即可，时间 o(n)
        for (int i = 0; i < nums.size(); ++i) 
        {
            // 检查 hashmap 中是否存在 target - nums[i]
            auto it = hashmap.find(target - nums[i]);
            // 存在直接返回，迭代器 it != end() 就表示存在
            if (it != hashmap.end())
                return {it->second, i};
            // 不存在就把 nums[i] 加入 hashmap
            hashmap[nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end

