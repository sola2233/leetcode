/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

// @lc code=start
/** 
 * 方法1.模拟，不太行，o(n^2)，99999999 用例直接超时
 * 方法2.数学，所有灯泡编号为 1, 2, 3, ..., n，则第 k 个灯泡切换次数为 k 的约数个数
 *       找到约数个数为奇数的数的个数，即完全平方数的个数
 *       由数论公式 [1,n] 中完全平方数的个数为 sqrt(n)
 */
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        // vector<bool> light(n, false);
        // // 一共 n 轮
        // for (int i = 1; i <= n; ++i)
        // {
        //     // 遍历灯泡
        //     for (int j = i - 1; j < n;)
        //     {
        //         // 可能会越界，代表这一轮结束
        //         if (j >= n)
        //             continue;
        //         // 打开或关闭开关
        //         light[j] = !light[j];
        //         j += i;
        //     }
        // }

        // return accumulate(light.begin(), light.end(), 0);
        return sqrt(n);
    }
};
// @lc code=end

