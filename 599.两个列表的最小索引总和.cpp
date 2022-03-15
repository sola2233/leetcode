/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
/** 
 * 哈希表
 */
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap;
        for (int i = 0; i < list2.size(); ++i)
            hashmap[list2[i]] = i;
        
        int idx_sum = INT32_MAX;
        vector<string> res;
        for (int i = 0; i < list1.size(); ++i)
        {
            if (!hashmap.count(list1[i]))
                continue;
            int sum = hashmap[list1[i]] + i;
            if (sum < idx_sum)
            {
                res.clear();
                idx_sum = sum;
            }
            if (sum == idx_sum)
                res.push_back(list1[i]);
        }
        return res;
    }
};
// @lc code=end

