/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
/** 
 * 贪心
 * 1.可以从前往后遍历，小饼干满足胃口小的
 * 2.可以从后往前遍历，大饼干满足胃口大的
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /** 升序排序 */
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        /** 孩子序号 */
        int child = 0;
        /** 饼干序号 */
        int cookie = 0;
        /** 循环条件 */
        while(child < g.size() && cookie < s.size())
        {
            if(g[child] <= s[cookie])
                child++;
            cookie++;
        }
        return child;
    }
};
// @lc code=end

