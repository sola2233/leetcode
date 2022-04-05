/** 
 * https://www.nowcoder.com/practice/03ba8aeeef73400ca7a37a5f3370fe68?tpId=37&tqId=21250&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 查找兄弟单词，字典中有 n 个单词，查找单词 x 的字典中的兄弟单词
 * 方法1.回溯，暴力方法，时间复杂度 o(n) + o(len(x)!)
 * 方法2.对 dict 中的每个单词，判断是否是兄弟单词，时间复杂度 o(n)
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

// 方法2.模拟
bool isBrother(string word, string x)
{
    // 长度不一样，或者两个单词相等都不是兄弟单词
    if (word.size() != x.size() || word == x)
        return false;
    // 比较两个单词中的字符数量是否一致
    vector<int> cnt1(26, 0);
    vector<int> cnt2(26, 0);
    for (int i = 0; i < word.size(); ++i)
    {
        cnt1[word[i] - 'a']++;
        cnt2[x[i] - 'a']++;
    }
    return cnt1 == cnt2;
}

int main()
{
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; ++i)
        cin >> dict[i];

    string x;
    int k;
    cin >> x >> k;

    // 排序
    sort(dict.begin(), dict.end());
    // 判断是否是兄弟单词
    int sum = 0, index = 0;
    for (int i = 0; i < n; ++i)
    {
        if (isBrother(dict[i], x))
        {
            sum++;
            // 找到第 k 个兄弟单词
            if (sum == k)
                index = i;
        }
    }
    cout << sum << endl;
    if (index)
        cout << dict[index] << endl;
        
    return 0;
}

#ifdef BACKTRACKING
// 方法1.回溯
// 词典，因为单词可能重复，所以用 map 计数
unordered_map<string, int> dict;
// 在 dict 中且不等于 x 的兄弟单词
set<string> res;
vector<bool> visited;
string path;
void backtracking(string& x)
{
    if (path.size() == x.size())
    {
        // 该兄弟单词在词典里
        if (dict.count(path) && path != x)
            res.insert(path);
        return;
    }
    
    for (int i = 0; i < x.size(); ++i)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        path.push_back(x[i]);
        backtracking(x);
        path.pop_back();
        visited[i] = false;
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        dict[s]++;
    }
    string x;
    int k;
    cin >> x >> k;
    
    visited.resize(x.size(), false);
    backtracking(x);
    
    // 计算兄弟单词个数
    int sum = 0;
    for (auto word : res)
        sum += dict[word];
    cout << sum << endl;
    // 寻找排序后第 k 个兄弟单词
    if (k <= sum)
    {
        auto it = res.begin();
        while (k > 0)
        {
            k -= dict[*it];
            it++;
        }
        it--;
        cout << *it << endl;
    }
        
    return 0;
}
#endif