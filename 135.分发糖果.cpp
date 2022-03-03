/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
/** 
 * 贪心
 */
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        /** 负例，孩子为0的情况 */
        if(size < 1)
            return size;
        /** 每个孩子分到的糖果数，初始化为1 */
        vector<int> num(size, 1);
        /** 从左往右遍历，保证右边评分更高的孩子糖果更多 */
        for(int i = 1; i < size; i++)
        {
            if(ratings[i] > ratings[i-1])
                num[i] = num[i-1] + 1;
        }
        /** 从右往左遍历，保证左边评分更高的孩子糖果更多 */
        for(int i = size - 1; i > 0; i--)
        {
            if(ratings[i-1] > ratings[i])
                num[i-1] = max(num[i-1], num[i] + 1);
        }
        /** 返回累加和，第三个参数指定累加的初始值 */
        return accumulate(num.begin(), num.end(), 0);
    }
};
// @lc code=end

