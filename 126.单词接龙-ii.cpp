/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
/** 
 * 好难，不会
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict;
        // 因为需要快速判断扩展出的单词是否在 wordList 里，因此需要将 wordList 存入哈希表
        for (const auto &w : wordList)
            dict.insert(w);
        // 终止字符串不存在则count返回0
        if (!dict.count(endWord))
            return ans;
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord}, q2{endWord};
        // 记录了单词是从哪些单词扩展而来，key：单词，value：单词列表，这些单词可以变换到 key ，它们是一对多关系
        unordered_map<string, vector<string>> next;
        bool reversed = false, found = false;
        // step1.广度优先遍历建图
        while (!q1.empty())
        {
            unordered_set<string> q;
            for (const auto &w : q1)
            {
                string s = w;
                for (size_t i = 0; i < s.size(); ++i)
                {
                    char ch = s[i];
                    for (int j = 0; j < 26; ++j)
                    {
                        s[i] = j + 'a';
                        if (q2.count(s))
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if (dict.count(s))
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    s[i] = ch;
                }
            }
            if (found)
                break;
            for (const auto &w : q)
                dict.erase(w);
            if (q.size() <= q2.size())
            {
                q1 = q;
            }
            else
            {
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        // step2.深度优先遍历找所有解
        if (found)
        {
            vector<string> path = {beginWord};
            backtracking(beginWord, endWord, next, path, ans);
        }
        return ans;
    }

    /**
     * 辅函数，回溯法 
     * @param 
     * @return 
     */
    void backtracking(const string &src, const string &dst, 
                        unordered_map<string, vector<string>> &next, 
                        vector<string> &path, vector<vector<string>> &ans)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (const auto &s : next[src])
        {
            path.push_back(s);
            backtracking(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end

