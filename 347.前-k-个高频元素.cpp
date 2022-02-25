/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
/** 
 * 方法1.桶排序
 * 参考https://leetcode-cn.com/problems/top-k-frequent-elements/solution/leetcode-di-347-hao-wen-ti-qian-k-ge-gao-pin-yuan-/
 * 首先依旧使用哈希表统计频率，统计完成后，创建一个数组，
 * 将频率作为数组下标，对于出现频率不同的数字集合，存入对应的数组下标即可。
 * 方法2.优先级队列
 * 先建立 hashmap 统计频率，接着将 hashmap 中的元素放进一个大小为 k 的小顶堆，按频率排序
 * hashmap 中没有元素时，小顶堆中就是 k 的频率最大的元素了
 * 注意：优先级队列的比较函数要自己实现
 */
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    // 桶排序
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     // 建立一个哈希表统计每个数字出现频率
    //     unordered_map<int, int> counts;
    //     int max_count = 0;
    //     // 计算数组中每个元素出现频率，并且找出最大频率
    //     for (const int &num : nums)
    //         max_count = max(max_count, ++counts[num]);

    //     vector<vector<int>> buckets(max_count + 1);
    //     // 将频率作为数组下标，对于出现频率不同的数字集合，存入对应的数组下标
    //     for (const auto &p : counts)
    //         buckets[p.second].push_back(p.first);

    //     vector<int> ans;
    //     // 从最高频率开始，将出现频率最高的k个数放入返回数组
    //     for (int i = max_count; i >= 0 && ans.size() < k; --i)
    //     {
    //         for (const int &num : buckets[i])
    //         {
    //             ans.push_back(num);
    //             if (ans.size() == k)
    //                 break;
    //         }
    //     }
    //     return ans;
    // }

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
            return a.second > b.second;
        }
    };

    // 优先级队列
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 建立一个哈希表统计每个数字出现频率
        unordered_map<int, int> counts;
        for (const int &num : nums)
            ++counts[num];

        // 放进一个大小为 k 的小顶堆中
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto& count : counts)
        {
            pq.push(count);
            if (pq.size() > k)
                pq.pop();
        }

        // 小顶堆中的数据转换成答案
        vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
// @lc code=end

