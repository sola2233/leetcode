/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
/** 
 * 滑动窗口
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> window; // 每种类型采摘的水果数量
        int count = 0; // 采摘的水果数量
        // 左闭右开
        int left = 0, right = 0;
        while (right < fruits.size())
        {
            int kind = fruits[right];
            // 增大窗口
            right++;
            // 更新窗口数据
            window[kind]++;

            // 缩小窗口
            while (window.size() == 3)
            {
                int kind = fruits[left];
                left++;
                // 更新窗口数据，删除空的种类
                window[kind]--;
                if (window[kind] == 0)
                    window.erase(kind);
            }

            // 更新答案
            if (right - left > count)
            {
                count = right - left;
            }
        }

        return count;
    }
};
// @lc code=end

