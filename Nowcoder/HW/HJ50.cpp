/** 
 * https://www.nowcoder.com/practice/9999764a61484d819056f807d2a91f1e?tpId=37&tqId=21273&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 四则运算
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int pos;
int n;
// 递归函数
int compute(string& s) {
    stack<int> stk;
    int num = 0;
    char pre_sign = '+';
    while (pos < n)
    {
        // 计算数字
        if (isdigit(s[pos]))
            num = 10 * num + (int)(s[pos] - '0');
        // 如果是符号
        if ((!isdigit(s[pos]) && !isspace(s[pos])) || pos == n - 1)
        {
            // 左括号，递归
            if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{')
            {
                pos++;
                // 遇到右括号返回之后也没有问题，因为右括号右边一定是符号
                num = compute(s);
            }
            // 正常处理符号
            int pre_num = 0;
            switch (pre_sign)
            {
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    pre_num = stk.top();
                    stk.pop();
                    stk.push(pre_num * num);
                    break;
                case '/':
                    pre_num = stk.top();
                    stk.pop();
                    stk.push(pre_num / num);
                    break;
            }
            // 右括号，返回
            if (s[pos] == ')' || s[pos] == ']' || s[pos] == '}')
            {
                pos++;
                break;
            }
            // 更新
            num = 0;
            pre_sign = s[pos];
        }
        // 更新 pos
        pos++;
    }

    int sum = 0;
    while (!stk.empty())
    {
        sum += stk.top();
        stk.pop();
    }
    return sum;
}

int main()
{
    string s;
    while (cin >> s)
    {
        pos = 0;
        n = s.size();

        int res = compute(s);
        cout << res << endl;
    }

    return 0;
}
