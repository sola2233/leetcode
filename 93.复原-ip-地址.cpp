/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
/** 
 * 回溯法，类似于 131 分割回文串，需要做分割
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
#if 1   // 回溯
    vector<string> res;
    vector<string> path;
    // 也可以用字符串，往里 insert(s.begin() + i + 1, '.') eraser(s.begin() + i + 1) 即可
    // string path; 
    vector<string> restoreIpAddresses(string s) {
        // 也算是剪枝了，因为根本分割不出 ip 地址
        if (s.size() > 12)
            return res;
        backtracking(s, 0);

        return res;
    }

    /**
     * 回溯法 
     * @param start_idx 下一层递归的开始分割位置
     */
    void backtracking(string& s, int start_idx)
    {   
        // 终止条件，这里用 path.size，不能用 start_idx，不然要添加很多条件，而且会多做很多无用选择
        if (path.size() == 4)
        {
            if (start_idx == s.size())
            {
                string str;
                for (int i = 0; i < path.size(); ++i)
                    str += path[i] + ".";
                str.pop_back();
                res.push_back(str);
            }
            return;
        }

        // 在本层选择列表做选择
        for (int i = start_idx; i < s.size(); ++i)
        {
            // 分割的子串
            string sub_str = s.substr(start_idx, i - start_idx + 1);
            // 剪枝，可以肯定，同一层后面的分割也不满足这三个条件，直接 return
            // 位数超过三位
            if (sub_str.size() > 3)
                break;
            // 三位，但是大于 255，不能直接和 255 比较，因为字符串比较是逐字符的
            if (sub_str.size() == 3 && sub_str > "255")
                break;
            // 首位为 0
            if (sub_str.size() > 1 && sub_str[0] == '0')
                break;
            path.push_back(sub_str);
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
#endif

#if 0   // 随便写的

    vector<string> restoreIpAddresses(string s) {
        cnt = 0;
        // 不满足条件的
        if (s.size() < 4 || s.size() > 12)
            return res;
        // 有特殊字符的
        for (char& ch : s)
        {
            if (!isdigit(ch))
                return res;
        }
        // 回溯
        backtracking(s, 0, "");

        return res;
    }

    vector<string> res;
    int cnt;
    /**
     * 回溯法 
     * @param path 放到参数里，不用手动 pop 了
     */
    void backtracking(string& s, int start_idx, string path)
    {
        // 剪枝
        if (cnt == 4 && start_idx < s.size())
            return;
        // base case
        if (start_idx == s.size())
        {
            if (cnt == 4)
            {
                path.pop_back();
                res.push_back(path);
            }
            return;
        }

        for (int i = start_idx; i < s.size(); ++i)
        {
            string word = s.substr(start_idx, i - start_idx + 1);
            int num = stoi(word);
            // 判断 ip 合法性
            if (word.size() > 3)
                break;
            else if (word[0] == '0' && word.size() > 1)
                break;
            else if (num < 0 || num > 255)
                break;
            
            cnt++;
            backtracking(s, i + 1, path + word + ".");
            cnt--;
        }
    }
#endif
};
// @lc code=end

