/** 
 * https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 购物单
 * 动态规划，01 背包 https://blog.nowcoder.net/n/9b7b33dfa9cc4956853dfb52de0c2de9?f=comment
 * dp[i][j]: 不超过 j 元，买 [1, i] 商品，最大的满意度
 * 状态转移: 只买主件、买主件和第一个附件、买主件和第二个附件、买主件和两个附件
 * 遍历顺序: 二维数组都可以，一维数组要从大到小遍历
 * base case: 初始化为 0
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // 由于价格是10的整数倍，处理一下以降低空间/时间复杂度
    n /= 10;
    // v[i][0]: 第 i 件物品本身的价值，v[i][1]: 第 i 件物品第一个附件的价值，v[i][2]: 第 i 件物品第二个附件的价值
    vector<vector<int>> v(m + 1, vector<int>(3, 0));
    // p[i][0]: 第 i 件物品本身的满意度，p[i][1]: 第 i 件物品第一个附件的满意度，p[i][2]: 第 i 件物品第二个附件的满意度
    vector<vector<int>> p(m + 1, vector<int>(3, 0));
    for (int i = 1; i <= m; ++i)
    {
        // 价值、重要度、主件还是附件
        int a, b, c;
        cin >> a >> b >> c;
        // 由于价格是10的整数倍，处理一下以降低空间/时间复杂度
        a /= 10;
        if (c == 0) // 主件
        {
            v[i][0] = a;
            p[i][0] = b * a;
        }
        else // 附件
        {
            if (v[c][1] == 0) // 是第一个附件
            {
                v[c][1] = a;
                p[c][1] = b * a;
            }
            else // 是第二个附件
            {
                v[c][2] = a;
                p[c][2] = b * a;
            }
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int v0 = v[i][0], p0 = p[i][0]; // 第 i 件商品本身的价值和满意度
            int v1 = v[i][1], p1 = p[i][1]; // 第 i 件商品第一个附件的价值和满意度
            int v2 = v[i][2], p2 = p[i][2]; // 第 i 件商品第二个附件的价值和满意度
            if (j >= v0) // 只买主件
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v0] + p0);
            else        // 钱不购买主件
                dp[i][j] = dp[i - 1][j];
            if (j >= v0 + v1) // 买主件和第一个附件，这里要和自己比较
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v0 - v1] + p0 + p1);
            if (j >= v0 + v2) // 买主件和第二个附件，这里要和自己比较
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v0 - v2] + p0 + p2);
            if (j >= v0 + v1 + v2) // 买主件和第一、二个附件，这里要和自己比较
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v0 - v1 - v2] + p0 + p1 + p2);
        }
    }
    // 恢复价格，乘 10
    cout << dp[m][n] * 10 << endl;
    
    return 0;
}