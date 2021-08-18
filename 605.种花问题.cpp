/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 贪心思想，从左往右遍历，可以种花的位置就种 
     */
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        /** 可以种花的位置数量 */
        int count = 0;
        /** 贪心策略，从左往右遍历，可以种花的位置就种 */
        for(int i = 0; i < size; i++)
        {
            /**
             * 判断当前位置是否能种花，四种情况 
             * 1.当前位置为0 + 当前位置为数组头 + 后一个位置为0
             * 2.当前位置为0 + 前一个位置为0   + 当前位置为数组尾
             * 3.当前位置为0 + 前一个位置为0   + 后一个位置为0
             * 4.当前位置为0 + 当前位置为数组头 + 当前位置为数组尾 (即只有一个元素)
             */
            if( flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i-1] == 0) &&      /** 位于数组头或前一位是0 */
                (i == size-1 || flowerbed[i+1] == 0) )  /** 位于数组尾或后一位是0 */
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        /** 返回 */
        return count >= n;
    }
};
// @lc code=end

