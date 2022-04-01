/** 
 * https://www.nowcoder.com/practice/66ca0e28f90c42a196afd78cc9c496ea?tpId=37&tqId=21256&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 整数与IP地址间的转换
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string ip;
    while (cin >> ip)
    {
        auto pos = ip.find(".");
        // 整型转 ip 地址
        if (pos == string::npos)
        {
            int a1, a2, a3, a4;
            // 这里要 stol，因为会超 int 范围
            long res = stol(ip);
            a1 = res >> 24;
            a2 = (res >> 16) & 0xFF;
            a3 = (res >> 8) & 0xFF;
            a4 = res & 0xFF;
            cout << a1 << "." << a2 << "." << a3 << "." << a4 << endl;
        }
        // ip 地址转整型
        else
        {
            // 这里要 long，不然移位之后会溢出
            long a1, a2, a3, a4;
            char ch;
            stringstream ss(ip);
            ss >> a1 >> ch >> a2 >> ch >> a3 >> ch >> a4;
            long res = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
            cout << res << endl;
        }
    }

    return 0;
}