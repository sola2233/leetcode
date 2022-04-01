/** 
 * https://www.nowcoder.com/practice/15e41630514445719a942e004edc0a5b?tpId=37&tqId=21293&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 矩阵乘法计算量估算
 * A * B 的计算量 [m, n] * [n, k] 为 m * n * k
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> size;
    // 输入每个矩阵的规模
    for (int i = 0; i < n; ++i)
    {
        int row, col;
        cin >> row >> col;
        size.push_back({row, col});
    }
    // 输入计算规则
    string s;
    cin >> s;
    // 估算计算量
    stack<char> stk;
    int cnt = 0;
    // s 中每个字符入栈
    for (int i = 0; i < s.size(); ++i)
    {
        // 遇到右括号就出栈，计算括号间的矩阵运算 (A * B) 的计算量
        if (s[i] == ')')
        {
            char matrix_b = stk.top(); // 矩阵 A 对应字符
            stk.pop();
            char matrix_a = stk.top(); // 矩阵 B 对应字符
            // 累加计算量
            cnt += size[matrix_a - 'A'][0] * size[matrix_a - 'A'][1] * size[matrix_b - 'A'][1];
            // 修改矩阵 A 的规模
            size[matrix_a - 'A'][1] = size[matrix_b - 'A'][1];
            stk.pop();  // 矩阵 A 出栈
            stk.pop();  // 左括号出栈
            stk.push(matrix_a); // 矩阵 A 入栈
        }
        // 其余情况直接入栈
        else
            stk.push(s[i]);
    }
    // 最后栈中就是得到的结果矩阵对应的字符 A，但是我们不需要，只需要 cnt 的结果
    cout << cnt << endl;
    
    return 0;
}