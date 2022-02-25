/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
/** 
 * 栈应用
 */
#include <string>
#include <deque>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> stk; // 选 deque 模拟栈，主要是为了拼接字符串方便
        // 遍历 path
        int n = path.size(), i = 0;
        while(i < n)
        {
            // 跳过 /
            if (i < n && path[i] == '/')
                i++;
            // 不是 / 就获得这一整个 string
            else
            {
                string temp;
                // 获得当前操作的字符串，可能是文件名，或 . 和 ..
                while (i < n && path[i] != '/')
                    temp += path[i++];
                // 如果是 .. 就弹出栈顶元素
                if (temp == ".." && !stk.empty())
                    stk.pop_back();
                // 如果是文件名就放进栈中，. 忽略
                else if (temp != ".." && temp != ".")
                    stk.push_back(temp); 
            }
        }

        string res = "/";
        // 依次弹出栈中元素
        while (!stk.empty())
        {
            res += stk.front() + "/";
            stk.pop_front();
        }
        // 删除最后一个 /，如果不是只有一个根目录的话
        if (res.size() > 1)
            res.pop_back();
        return res;
    }
};
// @lc code=end

