/** 
 * https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&tqId=21297&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 参数解析
 * 模拟
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        // 结尾添加一个空格，或者在循环中判断是否到达尾部
        s += " ";
        vector<string> param;
        // 记录当前参数起始位置，初始化为 0
        int pos = 0;
        for (int i = 0; i < s.size(); )
        {
            // 遇到空格，两个空格间的字符就是一个参数
            if (isspace(s[i]))
            {
                string tmp = s.substr(pos, i - pos);
                param.push_back(tmp);
                // 更新 i 和 pos
                ++i;
                pos = i;
            }
            // 遇到引号，往后找到下一个引号
            else if (s[i] == '"')
            {
                // 更新 i 和 pos
                pos = i + 1;
                i++;
                // 找到下一个引号
                while (s[i] != '"')
                    i++;
                string tmp = s.substr(pos, i - pos);
                param.push_back(tmp);
                // 更新 i 和 pos，跳过中间的空格
                i += 2;
                pos = i;
            }
            // 遇到正常字符，跳过
            else
                i++;
        }
        
        cout << param.size() << endl;
        for (auto str : param)
            cout << str << endl;
        
    }
    
    return 0;
}