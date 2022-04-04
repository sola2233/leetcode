/** 
 * https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&tqId=21288&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 查找两个字符串a,b中的最长公共子串
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    // 把 a 换成较短的串，这样才能保证先返回较短的串中最长公共子串
    if (a.size() > b.size())
        swap(a, b);

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    // base case
    // 遍历
    int max_len = 0;
    string res;
    for (int i = 1; i <= a.size(); ++i)
    {
        for (int j = 1; j <= b.size(); ++j)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            // 更新最长的公共子串
            if (dp[i][j] > max_len)
            {
                max_len = dp[i][j];
                res = a.substr(i - max_len, max_len);
            }
        }
    }
    cout << res << endl;
    
    return 0;
}