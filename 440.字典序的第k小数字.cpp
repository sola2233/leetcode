/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
/** 
 * 方法1.转字符串 + 大顶堆，不行，会超时
 * 方法2.前缀遍历前缀树，第 k 个数就是要找的数，这里前缀树是一棵十叉树
 */
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 方法1.超时的屑函数
    // int findKthNumber(int n, int k) {
    //     // 建立大顶堆
    //     priority_queue<string, vector<string>, less<string>> pq;
    //     for (int i = 1; i <= n; ++i)
    //     {
    //         pq.push(to_string(i));
    //         // 弹出栈顶最大元素
    //         if (pq.size() > k)
    //             pq.pop();
    //     }

    //     return stoi(pq.top());
    // }

    int findKthNumber(int n, int k) {
        int prefix = 1; // 前缀
        int p = 1;      // 指针，记录已经遍历过得数个数加 1
        while (p < k) // p == k 时，prefix 就是要找的数
        {
            int steps = getSteps(prefix, n);
            // 第 k 小的数不在以 prefix 为根的树中
            if (p + steps <= k) // 因为 p + steps 比遍历的数要多 1 个，所以这里加等号
            {
                // 去 prefix 的兄弟节点找
                prefix++;
                p += steps;;
            }
            // 第 k 小的数在以 prefix 为根的树中
            else if (p + steps > k)
            {
                // prefix 向下走一层
                prefix *= 10;
                p++;
            }
        }
        return prefix;
    }

    // 得到以 prefix 为根的树的在 [1, n] 范围内的节点个数，包括 prefix 节点
    int getSteps(int prefix, int n)
    {
        int steps = 0;
        // 每一层的头尾两个数
        long first = prefix, last = prefix;
        while (first <= n)
        {
            // 计算这一层的节点总数
            steps += min(last, (long)n) - first + 1;
            // 进入下一层
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }
};
// @lc code=end

