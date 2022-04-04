/** 
 * https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&tqId=21298&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 公共子串计算
 * 动态规划 https://programmercarl.com/0718.%E6%9C%80%E9%95%BF%E9%87%8D%E5%A4%8D%E5%AD%90%E6%95%B0%E7%BB%84.html#_718-%E6%9C%80%E9%95%BF%E9%87%8D%E5%A4%8D%E5%AD%90%E6%95%B0%E7%BB%84
 * dp[i][j]: s1[0, i-1] 和 s2[0, i-1] 的最长公共子串长度
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        // dp 大小加 1，为了计算方便
        vector<vector<int>> dp (s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int result = 0;
        // 遍历 s1
        for (int i = 1; i <= s1.size(); i++)
        {
            // 遍历 s2
            for (int j = 1; j <= s2.size(); j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // 记录最大的公共子串长度
                if (dp[i][j] > result)
                    result = dp[i][j];
            }
        }
        cout << result << endl;
    }
    
    return 0;
}