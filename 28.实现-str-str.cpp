/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
/** 
 * kmp
 * next[i]含义：模式串 P[0, i] 中，最长相等真前缀和真后缀长度，一定小于 i + 1，因为是真子串
 * [参考kmp解释](https://leetcode-cn.com/problems/implement-strstr/solution/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/)
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(); // 文本穿长度
        int m = needle.size(); // 模式串长度
        // 负例
        if (m == 0)
            return 0;
        // 1.构建 next 表
        vector<int> next(m);
        int j = 0; // j 指向前缀末尾
        next[0] = 0; // next[0] 初始化为 0，因为此时只有一个字符，没有真前缀和真后缀
        for (int i = 1; i < m; ++i) // i 指向后缀末尾
        {
            // 失配情况，直到 i 和 j 再次匹配或 j = 0
            while (j > 0 && needle[j] != needle[i])
                j = next[j - 1];
            // 匹配情况
            if (needle[i] == needle[j])
                j++;
            // next[i] 的值只有两种情况，匹配上或是 j = 0
            next[i] = j;
        }

        // 2.匹配文本串
        j = 0;
        for (int i = 0; i < n; ++i)
        {
            // 失配情况
            while (j > 0 && needle[j] != haystack[i])
                j = next[j - 1];
            // 匹配情况
            if (needle[j] == haystack[i])
                j++;
            // 匹配成功则返回位置
            if (j == m)
                return i - m + 1;
        }
        // 匹配失败
        return -1;
    }
};
// @lc code=end

