/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
/** 
 * 回溯法
 * 切割问题和组合问题很像
 * 组合问题：选取一个a之后，在bcdef中再去选取第二个，选取b之后在cdef中在选组第三个.....。
 * 切割问题：切割一个a之后，在bcdef中再去切割第二段，切割b之后在cdef中在切割第三段.....。
 * 相当于在每一层内，第一个选择是切一个，第二个选择是切前两个，以此类推
 * 可以继续在判断回文串上优化：
 * 1.动态规划预处理，dp[i][j] 数组判断 s.substr(i, j - i + 1)是否是回文
 * 2.备忘录 dp[i][j]，每次判断回文时记录，再遇到相同的直接返回，否则递归判断回文。。。
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path; // 放已经是回文的字符串
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);

        return res;
    }

    /**
     * 回溯法 
     * @param start_idx 下一层递归中起始位置
     */
    void backtracking(string s, int start_idx)
    {
        // 终止条件，能切割到最后，说明前面都是回文
        if (start_idx == s.size())
        {
            res.push_back(path);
            return;
        }

        // 在选择列表做选择
        for (int i = start_idx; i < s.size(); ++i)
        {
            // 切割子串，同一层内，随着 i 增大，切割的字符也在变多
            string sub_s = s.substr(start_idx, i - start_idx + 1);
            // 剪枝，不是回文就跳过这条树枝，不能返回，因为后面的树枝上可能有回文
            if (!isPalindrome(sub_s))
                continue;
            path.push_back(sub_s);
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    // 判断是否是回文
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

