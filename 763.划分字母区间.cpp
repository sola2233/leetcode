/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
/**
 * 贪心思想
 * 可以分为如下两步：
 * 1.统计每一个字符最后出现的位置
 * 2.从头遍历字符，并更新字符的最远出现下标，
 * 如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
#if 1
    vector<int> partitionLabels(string s) {
        int n = s.size();
        // 遍历字符串
        vector<int> ends(26, 0);    // 保存每个字符最后出现的位置
        for (int i = 0; i < s.size(); ++i)
        {
            char idx = s[i] - 'a';
            ends[idx] = i;
        }

        vector<int> res;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int ch = s[i] - 'a';
            // note 这里是第一次比较，更新右边界
            right = max(right, ends[ch]);
            // note 这里是第二次比较，到达某个字符的最远边界，划分一次
            if(i == right)
            {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
#endif


#if 0   // 写了一大坨，居然 ac 了

    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mp;
        // 计数
        for (int i = 0; i < s.size(); ++i)
        {
            if (!mp.count(s[i]))
                mp[s[i]] = {i, i};
            else
                mp[s[i]][1] = i;
        }

        // 抽取其中的 vector
        vector<vector<int>> lens;
        for (auto ite = mp.begin(); ite != mp.end(); ite++)
        {
            lens.push_back(ite->second);
        }
        // 按左边界升序排序，相同按右边界降序
        sort(lens.begin(), lens.end(), [](auto& a, auto& b) -> bool {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        // 寻找重叠区间
        vector<int> res;
        int start = 0, end = lens[0][1];
        for (int i = 1; i < lens.size(); ++i)
        {
            if (lens[i][1] <= end)
                continue;
            if (lens[i][0] < end)
            {
                end = lens[i][1];
            }
            else if (lens[i][0] > end)
            {
                res.push_back(end - start + 1);
                start = lens[i][0];
                end = lens[i][1];
            }
        }

        int sum = accumulate(res.begin(), res.end(), 0);
        if (sum < s.size())
            res.push_back(s.size() - sum);

        return res;
    }
#endif
};

// @lc code=end

