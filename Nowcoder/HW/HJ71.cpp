/** 
 * https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&tqId=21294&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 字符串通配符
 * 递归
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool match(string& s1, string &s2, int i, int j)
{
    // base case
    // 两个字符串同时结束,返回true
    if (i == s1.size() && j == s2.size())
        return true;
    // 两个字符串中有一个先结束，返回false
    if (i == s1.size() || j == s2.size())
        return false;
    
    // 遇到到 ？，则算匹配到一个字符，跳过一个位置
    if (s1[i] == '?' && isalnum(s2[j]))
        return match(s1, s2, i + 1, j + 1);
    // 遇到到 *，匹配多个，匹配一个，不匹配
    else if (s1[i] == '*' && isalnum(s2[j]))
    {
        // 去掉重复的 *，效果都一样，但是增加了复杂的
        while (s1[i] == '*')
            i++;
        // 对于重复的 *，找到最后一个 * 的位置
        i--;
        return match(s1, s2, i, j+1) || match(s1, s2, i+1, j+1) || match(s1, s2, i+1, j);
    }
    // 当前两字符相等，则进行下一个字符的匹配
    else if (s1[i] == s2[j])
        return match(s1, s2, i + 1, j + 1);
    else
        return false;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        // 转小写
        for (auto& ch : s1)
        {
            if (isupper(ch))
                ch = tolower(ch);
        }
        for (auto& ch : s2)
        {
            if (isupper(ch))
                ch = tolower(ch);
        }
        // 匹配
        bool res = match(s1, s2, 0, 0);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    
    return 0;
}