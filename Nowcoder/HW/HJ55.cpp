/** 
 * https://www.nowcoder.com/practice/ba241b85371c409ea01ac0aa1a8d957b?tpId=37&tqId=21278&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 挑7
 * 模拟
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int cnt = 0;
    for (int i = 7; i <= n; ++i)
    {
        if (i % 7 == 0)
            cnt++;
        else
        {
            string str = to_string(i);
            for (auto& ch : str)
            {
                if (ch == '7')
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
    
    return 0;
}