/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
/** 
 * 首先依旧使用哈希表统计频率，统计完成后，创建一个数组，
 * 将频率作为数组下标，对于出现频率不同的数字集合，存入对应的数组下标即可。
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    /**
     * 返回一个数组 nums 中出现频率前 k 高的元素，按任意顺序返回 
     * @param nums 待查询无序数组
     * @param k 
     * @return ans 频率前 k 高的元素数组
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 建立一个哈希表统计每个数字出现频率
        unordered_map<int, int> counts;
        int max_count = 0;
        // 计算数组中每个元素出现频率，并且找出最大频率
        for (const int &num : nums)
            max_count = max(max_count, ++counts[num]);

        vector<vector<int>> buckets(max_count + 1);
        // 将频率作为数组下标，对于出现频率不同的数字集合，存入对应的数组下标
        for (const auto &p : counts)
            buckets[p.second].push_back(p.first);

        vector<int> ans;
        // 从最高频率开始，将出现频率最高的k个数放入返回数组
        for (int i = max_count; i >= 0 && ans.size() < k; --i)
        {
            for (const int &num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};
// @lc code=end

