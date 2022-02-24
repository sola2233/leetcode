/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
/** 
 * 双指针
 */
#include <string>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skip_s = 0, skip_t = 0;
        // 从后向前遍历，依次比较后面的非退格符号，因为退格符号只会影响前面的字符
        while (i >= 0 || j >= 0)
        {
            // 1.移动 s 的指针
            while (i >= 0)
            {
                // 遇到退格记录
                if (s[i] == '#')
                {
                    skip_s++;
                    i--;
                }
                // 遇到字符但是需要退格
                else if (s[i] != '#' && skip_s > 0)
                {
                    skip_s--;
                    i--;
                }
                // 遇到不用退格的正常字符停止
                else
                    break;
            }
            // 2.移动 t 的指针
            while (j >= 0)
            {
                // 遇到退格记录
                if (t[j] == '#')
                {
                    skip_t++;
                    j--;
                }
                // 遇到字符但是需要退格
                else if (t[j] != '#' && skip_t > 0)
                {
                    skip_t--;
                    j--;
                }                
                // 遇到不用退格的正常字符停止
                else
                    break;
            }
            // 3.比较两个字符
            if (i >= 0 && j >= 0)
            {
                // 两个字符不等，返回 false
                if (s[i] != t[j])
                    return false;
            }
            // 如果两个字符串有一个为空
            else if (i < 0 || j < 0)
            {
                // 只要两个字符下标 i j 有一个大于等于 0 说明两个字符串不等
                if (i >= 0 || j >= 0)
                    return false;
                // 两个都小于 0 说明都是空字符串，也相等
            }
            i--;
            j--;
        }

        return true;
    }
};
// @lc code=end

