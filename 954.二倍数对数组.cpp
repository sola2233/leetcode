/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

// @lc code=start
/** 
 * 模拟
 * hash + 排序
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        // hash 计数
        unordered_map<int, int> cnt;
        for (auto& num : arr)
            cnt[num]++;
        
        // 0 要特殊处理，必须是偶数个
        if (cnt[0] % 2 != 0)
            return false;
        
        // 按绝对值升序，这里创建一个新的数组，是为了数字不重复
        vector<int> vals;
        for (auto& [k, v] : cnt) // 学习新的写法
            vals.push_back(k);
        sort(vals.begin(), vals.end(), [](int& a, int& b) -> bool {
            return abs(a) < abs(b);
        });

        for (int& num : vals)
        {
            if (cnt[num * 2] < cnt[num])
                return false;
            cnt[num * 2] -= cnt[num];
        }

        return true;
    }
};
// @lc code=end

