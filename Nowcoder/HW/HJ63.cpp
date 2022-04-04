/** 
 * https://www.nowcoder.com/practice/e8480ed7501640709354db1cc4ffd42a?tpId=37&tqId=21286&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * DNA序列
 * 滑动窗口
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    while (cin >> s >> n)
    {
        string res;
        int cnt;
        int max_cnt = 0;
        // 滑动窗口，左闭右开
        int left = 0, right = 0;
        while (right < s.size())
        {
            // 扩大窗口
            char cur = s[right];
            right++;
            if (cur == 'C' || cur == 'G')
                cnt++;
            
            // 缩小窗口条件
            if (right - left >= n)
            {
                // 更新结果
                if (cnt > max_cnt)
                {
                    max_cnt = cnt;
                    res = s.substr(left, right - left);
                }
                char cur = s[left];
                left++;
                if (cur == 'C' || cur == 'G')
                    cnt--;
            }
        }
        cout << res << endl;
    }

    return 0;
}