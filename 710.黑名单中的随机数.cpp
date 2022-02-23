/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
/** 
 * 数组+hash
 * 首先不能储存白名单，因为 n 很大，会超出时间和空间限制，索引只能做黑名单映射
 * 1.我们在 [0, sz - 1] 中随机选择数
 * 2.如果这个数在黑名单中，就把它映射到数组尾部一个不在黑名单中的数上
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 可以选择的索引范围
    int sz;
    // 黑名单映射，val 到 index 的映射
    unordered_map<int, int> val2idx;
    Solution(int n, vector<int>& blacklist) {
        // 初始化
        sz = n - blacklist.size();
        for (int& num : blacklist)
            val2idx[num] = num;
        // 黑名单映射
        int last = n - 1;
        for (int& num : blacklist)
        {
            // num 已经在区间 [sz, n-1]中则忽略
            if (num >= sz)
                continue;
            // 在尾部找到不在黑名单中的第一个数
            while (val2idx.count(last))
                --last;
            // num 映射到尾部一个不在黑名单中的数
            val2idx[num] = last;
            --last;
        }
    }
    
    int pick() {
        int val = rand() % sz;
        // 在黑名单中则找对应在尾部那个数
        if (val2idx.count(val))
            return val2idx[val];
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

