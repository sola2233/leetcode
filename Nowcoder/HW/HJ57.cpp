/** 
 * https://www.nowcoder.com/practice/49e772ab08994a96980f9618892e55b6?tpId=37&tqId=21280&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 高精度整数加法
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // 保存结果，最后要倒序输出或者 reverse 一下
    string res;
    // 进位
    int quotient = 0;
    // 双指针
    int p1 = s1.size() - 1, p2 = s2.size() - 1;
    // 从后往前加
    while (p1 >= 0 && p2 >= 0)
    {
        int num1 = s1[p1] - '0';
        int num2 = s2[p2] - '0';
        int sum = num1 + num2 + quotient;
        quotient = sum / 10;
        int remainder = sum % 10;
        res += to_string(remainder);
        p1--;
        p2--;
    }
    // 继续加 s1 中没加完的数
    while (p1 >= 0)
    {
        if (quotient > 0)
        {
            int num1 = s1[p1] - '0';
            int sum = num1 + quotient;
            quotient = sum / 10;
            int remainder = sum % 10;
            res += to_string(remainder);            
            p1--;
        }
        else
        {
            res += s1[p1];
            p1--;
        }
    }
    // 继续加 s2 中没加完的数
    while (p2 >= 0)
    {
        if (quotient > 0)
        {
            int num2 = s2[p2] - '0';
            int sum = num2 + quotient;
            quotient = sum / 10;
            int remainder = sum % 10;
            res += to_string(remainder);            
            p2--;
        }
        else
        {
            res += s2[p2];
            p2--;
        }
    }
    // 最后商数如果为 1，还要再加，这里直接输出即可
    if (quotient > 0)
        cout << quotient;
    // 逆序输出
    for (auto it = res.rbegin(); it != res.rend(); ++it)
        cout << *it;
    cout << endl;
    
    return 0;
}