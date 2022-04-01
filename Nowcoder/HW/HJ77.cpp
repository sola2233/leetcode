/** 
 * https://www.nowcoder.com/practice/97ba57c35e9f4749826dc3befaeae109?tpId=37&tqId=21300&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 火车进站
 * dfs + 栈
 */
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

// 用 set 是为了去重，不知道为什么，用 vector 会把结果重复一遍
set<string> res;

/**
 * 回溯法，dfs，火车进车站相当于进栈，只有最后进去的才能先出来 
 * @param trans 等待进栈的火车
 * @param stk 相当于车站，火车就是要进栈
 * @param path 火车出栈的某个顺序
 * @param is_push 现在是火车入栈还是栈中火车出栈
 */
void dfs(queue<int> trans, stack<int> stk, string path, bool is_push)
{
    // base case，没有要进栈的火车了
    if (trans.empty())
    {
        // 车站中的火车全部出栈
        while (!stk.empty())
        {
            path += to_string(stk.top());
            stk.pop();
        }
        // 某条路径加到结果中，set 会自动排序
        res.insert(path);
        return;
    }
    
    // 入栈
    if (is_push)
    {
        stk.push(trans.front());
        trans.pop();
    }
    // 出栈
    else
    {
        // 栈是空，直接返回
        if (stk.empty())
            return;
        path += to_string(stk.top());
        stk.pop();
    }
    // 递归
    dfs(trans, stk, path, false);
    dfs(trans, stk, path, true);
}

int main()
{
    int n;
    cin >> n;
    queue<int> trans;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        trans.push(num);
    }
    
    stack<int> stk;
    string path;
    dfs(trans, stk, path, true);
    
    // 输出结果
    for (auto& str : res)
    {
        for (auto& ch : str)
            cout << (ch - '0') << " ";
        cout << endl;
    }
    
    return 0;
}

