/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
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

