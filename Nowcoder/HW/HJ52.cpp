/** 
 * https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&tqId=21275&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 计算字符串的编辑距离 https://programmercarl.com/0072.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.html#%E6%80%9D%E8%B7%AF
 * 动态规划
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    // base case，到空字符串的编辑距离就是字符串的 size，即全部删掉
    for (int i = 0; i <= s1.size(); ++i)
        dp[i][0] = i;
    for (int j = 0; j <= s2.size(); ++j)
        dp[0][j] = j;
    // 遍历
    for (int i = 1; i <= s1.size(); ++i)
    {
        for (int j = 1; j <= s2.size(); ++j)
        {
            if (s1[i - 1] != s2[j - 1])
            {
                // min 内表示删 s1，删 s2，替换 s1 或 s2
                // 这里没有增，是因为增加一个元素相当于删除另一个字符串中的元素
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
            else
                dp[i][j] = dp[i - 1][j - 1];
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    
    return 0;
}