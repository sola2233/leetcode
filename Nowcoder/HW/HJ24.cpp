/** 
 * https://www.nowcoder.com/practice/6d9d69e3898f45169a441632b325c7b4?tpId=37&tqId=21247&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 合唱队
 * 动态规划，最长上升子序列
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
    
    // left[i]: [0, i] 中以 i 结尾的左侧最长上升子序列
    vector<int> left(n, 1);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (h[i] > h[j])
                left[i] = max(left[i], left[j] + 1);
        }
    }
    
    // right[i]: [n - 1, i] 中以 i 结尾的右侧最长上升子序列，这里从右往左遍历
    vector<int> right(n, 1);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (h[i] > h[j])
                right[i] = max(right[i], right[j] + 1);
        }
    }
    // 计算 left[i] + right[i] - 1 的最大值，即最长合唱队列的人数
    int max_len = 0;
    for (int i = 0; i < n; ++i)
        // 这里要减 1，因为第 i 个人实际上算了两次
        max_len = max(max_len, left[i] + right[i] - 1);
    
    cout << n - max_len << endl;
    
    return 0;
}