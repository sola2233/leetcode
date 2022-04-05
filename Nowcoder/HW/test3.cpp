/** 
 * 测试试卷第三题，求一个长度不超过 10 的字符串的全排列
 * 输入: 字符串 s
 * 输出: s 全排列数，包括自己
 * 回溯法：需要去重，直接用 set 去重会超内存
 * 先对 s 排序，使得相同的字符排在一起
 * 在回溯算法每一层进行选择时，如果同一层的前一个数和自己一样，则跳过当前的数
 * 也可以在同一树枝上去重，但是效率没有同一树层去重高
 */
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> visited;
string path;
vector<string> res;
void dfs(string& s)
{
    if (path.size() == s.size())
    {
        res.push_back(path);
        return;
    }
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (i > 0 && s[i] == s[i - 1] && visited[i - 1] == false)
            continue;
        if (visited[i])
            continue;
        visited[i] = true;
        path.push_back(s[i]);
        dfs(s);
        visited[i] = false;
        path.pop_back();
    }
}

int main()
{
    string s;
    while (cin >> s)
    {
        sort(s.begin(), s.end());
        res.clear();
        visited.resize(s.size(), false);
        dfs(s);
        cout << res.size() << endl;
    }
    
    return 0;
}
