/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
/** 
 * 贪心，每次都改变最小的元素
 * 方法1.大顶堆，小顶堆
 * 遍历一遍，找到 k 个最小的元素
 * 方法2.贪心，先找负数，再找最小的正数，反复转变，用完 k
 * 这里其实用了两次贪心！
 * 第一次贪心：
 * 局部最优：让绝对值大的负数变为正数，当前数值达到最大，整体最优：整个数组和达到最大。
 * 处理之后，如果K依然大于0，此时的问题是一个有序正整数序列，如何转变K次正负，让 数组和 达到最大。
 * 第二次贪心：
 * 局部最优：只找数值最小的正整数进行反转，当前数值可以达到最大（例如正整数数组{5, 3, 1}，反转1 得到-1 比 反转5得到的-5 大多了），全局最优：整个 数组和 达到最大。
 * 第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
 * 第二步：从前向后遍历，遇到负数将其变为正数，同时K--
 * 第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
 * 第四步：求和
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 方法1
    // int largestSumAfterKNegations(vector<int>& nums, int k) {
    //     priority_queue<int, vector<int>, less<int>> pq_greater;
    //     int sum = 0;
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         pq_greater.push(nums[i]);
    //         if (pq_greater.size() > k)
    //         {
    //             sum += pq_greater.top();
    //             pq_greater.pop();
    //         }
    //     }

    //     priority_queue<int, vector<int>, greater<int>> pq_less;
    //     while (!pq_greater.empty())
    //     {
    //         pq_less.push(pq_greater.top());
    //         pq_greater.pop();
    //     }

    //     for (int i = 0; i < k; ++i)
    //     {
    //         int num = -pq_less.top();
    //         pq_less.pop();
    //         pq_less.push(num);
    //     }

    //     while (!pq_less.empty())
    //     {
    //         sum += pq_less.top();
    //         pq_less.pop();
    //     }

    //     return sum;
    // }

    // 方法2
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        // 按绝对值降序排序
        sort(nums.begin(), nums.end(), [](auto& a, auto& b) -> bool {
            return abs(a) > abs(b);
        });

        // 遍历一遍，把负数全部变为正数
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }

        // 如果 k 还没到 0，nums 一定全为正数了，所以最后一个数就是最小正数
        // 不用真的反复变，只要看 k 是奇数还是偶数，偶数不变，奇数乘上 -1
        if (k % 2 == 1) nums[n - 1] = -nums[n - 1];
        // 累加
        int res = 0;
        for (auto& num : nums)
            res += num;

        return res;
    }
};
// @lc code=end

