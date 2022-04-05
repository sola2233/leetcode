/** 
 * https://www.nowcoder.com/practice/2aa32b378a024755a3f251e75cbf233a?tpId=37&tqId=21252&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 字符串加解密
 * 方法1.模拟
 * 方法2.建立字母加解密表，直接查表
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encode(string s)
{
    for (auto& ch : s)
    {
        if (islower(ch)) // 是小写字母
        {
            if (ch == 'z') // 是 'z'
                ch = 'A';
            else // 其余字母
                ch = toupper(ch + 1);
        }
        else if (isupper(ch)) // 是大写字符
        {
            if (ch == 'Z') // 是 'Z'
                ch = 'a';
            else
                ch = tolower(ch + 1);
        }
        else if (isdigit(ch)) // 是数字
        {
            if (ch == '9') // 是 9
                ch = '0';
            else
                ch = ch + 1;
        }
    }
    return s;
}

string decode(string s)
{
    for (auto& ch : s)
    {
        if (islower(ch)) // 是小写字母
        {
            if (ch == 'a') // 是 'a'
                ch = 'Z';
            else // 其余字母
                ch = toupper(ch - 1);
        }
        else if (isupper(ch)) // 是大写字符
        {
            if (ch == 'A') // 是 'A'
                ch = 'z';
            else
                ch = tolower(ch - 1);
        }
        else if (isdigit(ch)) // 是数字
        {
            if (ch == '0') // 是 0
                ch = '9';
            else
                ch = ch - 1;
        }
    }    
    return s;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << encode(s1) << endl;
    cout << decode(s2) << endl;
    
    return 0;
}