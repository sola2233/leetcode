/** 
 * https://www.nowcoder.com/practice/24e6243b9f0446b081b1d6d32f2aa3aa?tpId=37&tqId=21326&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * Redraiment的走法
 * 动态规划，最长递增子序列
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    
    vector<int> dp(n, 1);
    int max_len = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (h[i] > h[j])
                dp[i] = max(dp[i], dp[j] + 1);
            max_len = max(max_len, dp[i]);
        }
    }
    cout << max_len << endl;
    
    return 0;
}