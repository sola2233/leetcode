/** 
 * https://www.nowcoder.com/practice/caf35ae421194a1090c22fe223357dca?tpId=37&tqId=21330&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 求解立方根
 * 方法1.二分，写得模模糊糊的，然后就对了
 * 方法2.牛顿迭代法
 */
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    double y;
    while (cin >> y)
    {
        // f(x) = x^3 - y，令f(x) = 0
        double x = 1.0;
        while (abs(x * x * x - y) > 0.01)
        {
            x = x - (x * x * x - y) / (3 * x * x);
        }
        cout << fixed << setprecision(1) << x << endl;
    }
    
    return 0;
}

#ifdef BINARY_SEARCH
int main()
{
    double x;
    while (cin >> x)
    {
        double left = min(-1.0, x), right = max(1.0, x);
        while (abs(right - left) > 0.01)
        {
            double mid = (right + left) / 2.0;
            double res = x / mid / mid;
            
            if (mid < res)
                left = mid;
            else if (mid > res)
                right = mid;
            else
                right = mid;
        }
        cout << fixed << setprecision(1) << left << endl;
    }
    
    return 0;
}
#endif