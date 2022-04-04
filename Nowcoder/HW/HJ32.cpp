/** 
 * https://www.nowcoder.com/practice/3cd4621963e8454594f00199f4536bb1?tpId=37&tqId=21255&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 密码截取
 * 动态规划，最长回文子串 https://programmercarl.com/0647.%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.html#%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92
 * dp[i][j]: s[i, j] 是否是回文字符串
 * 遍历顺序要从下往上，从左往右
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int max_len = 1;
        // 从下往上，从左往右遍历
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                // 首位字符相等
                if (s[i] == s[j])
                {
                    // 只有一个字符或相邻两个字符
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                    }
                    // 超过两个字符时
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        max_len = max(max_len, j - i + 1);
                    }
                }
            }
        }
        cout << max_len << endl;
    }
    
    return 0;
}