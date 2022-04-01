/** 
 * https://www.nowcoder.com/practice/e0480b2c6aa24bfba0935ffcca3ccb7b?tpId=37&tqId=21305&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 将真分数分解为埃及分数
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a, b; // 分子，分母
    char ch;
    // 不错的输入方法
    while (cin >> a >> ch >> b)
    {
        // 方法1.分解为埃及分数 a 个 1/b
        // string res;
        // for (int i = 0; i < a - 1; ++i)
        // {
        //     res += "1/" + to_string(b) + "+";
        // }
        // res += "1/" + to_string(b);
        // cout << res << endl;       

        // 方法2.没仔细看
        while (a != 1)
        {
            if (b % a == 0)
            {
                b = b / a;
                break;
            }
            
            if (b % (a - 1) == 0)
            {
                cout << "1/" << b / (a - 1) << "+";
                break;
            }
            
            int q, r;
            q = b / a;
            r = b % a;
            cout << "1/" << q + 1 << "+";
            a = a - r;
            b = (q + 1) * b;
        }
        cout << "1/" << b << endl;
    }
    
    return 0;
}