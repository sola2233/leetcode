/** 
 * https://www.nowcoder.com/practice/995b8a548827494699dc38c3e2a54ee9?tpId=37&tqId=21313&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 合法IP
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isok(string str)
{
    // 加一个尾部的 '.'
    str.push_back('.');
    int index = 0;
    vector<string> v;
    // 记录以 '.' 分割的字符串
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            // i 是 '.' 的下标
            string s = str.substr(index, i - index);
            // s 为空
            if (s.size() == 0)
                return false;
            // s 有前缀 0 或 其他符号，如 '+'
            if (s.size() > 1 && (s[0] < '1' || s[0] > '9'))
                return false;
            v.push_back(s);
            index = i + 1;
        }
    }

    // ip 地址没有四个整数就是错的
    if (v.size() != 4)
        return false;
        
    for (auto s : v)
    {
        int x = stoi(s);
        if (x < 0 || x > 255)
            return false;
    }
    return true;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (isok(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}