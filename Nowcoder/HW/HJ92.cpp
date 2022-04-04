/** 
 * https://www.nowcoder.com/practice/2c81f88ecd5a4cc395b5308a99afbbec?tpId=37&tqId=21315&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 在字符串中找出连续最长的数字串
 * 模拟，一次遍历即可
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
        string res;
        int max_len = 0;
        int len = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // 计算当前数字字符串长度
            if (isdigit(s[i]))
                len++;
            else
                len = 0;
            // 超过最大数字字符串长度就更新
            if (len > max_len)
            {
                max_len = len;
                res.clear();
                res += s.substr(i - len + 1, len);
            }
            // 相等就添加这个新的子串
            else if (len == max_len)
                res += s.substr(i - len + 1, len);
        }
        cout << res << "," << max_len << endl;
    }
    return 0;
}