/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
/** 
 * 贪心算法
 * 先排序在插入
 * 1.排序规则：两个维度 H 和 K，按照 H 降序，若 H 相同再按 K 升序排序
 * 2.遍历排序后的数组，根据K插入到K的位置上
 * 核心思想：高个子先站好位，矮个子插入到K位置上，前面肯定有K个高个子，矮个子再插到前面也满足K的要求 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 可以进一步优化，用 list 代替 vector，因为 vector 的插入操作复杂度为 o(n)
        vector<vector<int>> res;
        res.reserve(people.size());
        int n = people.size();
        // 负例
        if(n < 2)
            return people;
        // 按 H 和 K 排序
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        // 按 K 插入到合适位置
        for(int i = 0; i < n; i++)
        {
            int idx = people[i][1]; // 要插入的位置
            res.insert(res.begin() + idx, people[i]);
        }

        return res;
    }
};
// @lc code=end

