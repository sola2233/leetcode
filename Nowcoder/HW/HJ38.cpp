/** 
 * https://www.nowcoder.com/practice/2f6f9339d151410583459847ecc98446?tpId=37&tqId=21261&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 求小球落地5次后所经历的路程和第5次反弹的高度
 * 模拟
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int height;
    while (cin >> height)
    {
        double h = height;
        double sum = h;
        for (int i = 1; i < 5; ++i)
        {
            h /= 2.0;
            sum += h * 2.0;
        }
        cout.precision(6);
        cout << sum << endl;
        cout << h / 2.0 << endl;
    }
    return 0;
}