/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
/** 
 * 双指针移除头尾和中间冗余的空格 o(n)
 * 反转整个字符串，再反转每个单词
 * 去除多余的空格就相当于去除数组中重复的的数字
 */
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        // 去除空格
        RemoveExtraSpace(s);
        // 整个字符串反转
        Reverse(s, 0, s.size() - 1);
        // 依次反转每个单词
        int n = s.size();
        int slow = 0, fast = 0;
        while (fast < n)
        {
            // 遇到空格
            if (s[fast] == ' ')
            {
                Reverse(s, slow, fast - 1);
                slow = fast + 1;
            }
            fast++;
        }
        // 最后一个单词后面没有空格
        Reverse(s, slow, fast - 1);

        return s;
    }

    // 左闭右闭，反转 [left, right] 区间字符串
    void Reverse(string& s, int left, int right)
    {
        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }

    // 移除头部、中间冗余、尾部空格
    void RemoveExtraSpace(string& s)
    {
        int n = s.size();
        int slow = 0, fast = 0;

        // 移除头部空格
        while (n > 0 && fast < n && s[fast] == ' ')
            fast++;
        
        // 移除中间冗余空格，顺便填充前面的部分
        while (fast < n)
        {
            // 移除冗余空格，就是把 fast 移动到最后一个空格处
            while (s[fast] == ' ' && fast + 1 < n && s[fast] == s[fast + 1])
                fast++;
            // 填充前面
            s[slow++] = s[fast++];
        }

        // 左闭右开，[0, slow) 是我们维护的一个字符串
        // 移除尾部空格，如果尾部有空格，一定只有一个，因为之前已经移除了冗余空格
        if (slow - 1 > 0 && s[slow - 1] == ' ')
            s.resize(slow - 1); // 移除尾部的一个空格
        else
            s.resize(slow); // 重新设置字符串大小
    }
};
// @lc code=end

