/** 
 * https://www.nowcoder.com/practice/184edec193864f0985ad2684fbc86841?tpId=37&tqId=21243&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 密码验证合格程序
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int caseTwo(string& s)
{
    vector<int> use(4, 0); 
    int cnt = 0;
    for (auto ch : s)
    {
        if (cnt >= 3)
            break;
        if (islower(ch) && use[0] == 0)
        {
            use[0] = 1;
            cnt++;
        }
        else if (isupper(ch) && use[1] == 0)
        {
            use[1] = 1;
            cnt++;
        }
        else if (isdigit(ch) && use[2] == 0)
        {
            use[2] = 1;
            cnt++;
        }
        else if (!isalnum(ch) && use[3] == 0)
        {
            use[3] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    string s;
    while (cin >> s)
    {
        // 检测长度是否大于 8
        if (s.size() < 8)
        {
            cout << "NG" << endl;
            continue;
        }
        // 四种条件：小写、大写、数字、其他符号，包含三种条件
        int cnt = caseTwo(s);
        if (cnt < 3)
        {
            cout << "NG" << endl;
            continue;
        }
        // 检测是否有长度大于 2 的包含公共元素的重复子串
        bool invalid = false;
        for (int i = 0; i < s.size() - 3; ++i)
        {
            string tmp = s.substr(i, 3);
            if (s.find(tmp, i + 1) != string::npos)
            {
                invalid = true;
                break;
            }
        }
        if (invalid)
        {
            cout << "NG" << endl;
            continue;
        }
        // 全部满足
        cout << "OK" << endl;
    }
    
    return 0;
}