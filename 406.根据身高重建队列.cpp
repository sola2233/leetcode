/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
/** 
 * 贪心算法
 * 先排序在插入
 * 1.排序规则：按照先H高度降序，K个数升序排序
 * 2.遍历排序后的数组，根据K插入到K的位置上
 * 核心思想：高个子先站好位，矮个子插入到K位置上，前面肯定有K个高个子，矮个子再插到前面也满足K的要求 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
        /** 为空或为1时 */
        if(size < 2)
            return people;
        /** 按身高降序排序，身高相同按第二个参数K升序 */
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        /** 返回数组 */
        vector<vector<int>> ret;
        /** 遍历people */
        for(int i = 0; i < size; i++)
        {
            /** 根据第二个参数K直接插入到K位置上 */
            ret.insert(ret.begin() + people[i][1], people[i]);
        }

        return ret;
    }
};
// @lc code=end

