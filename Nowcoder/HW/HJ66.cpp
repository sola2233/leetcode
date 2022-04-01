/** 
 * https://www.nowcoder.com/practice/ca6ac6ef9538419abf6f883f7d6f6ee5?tpId=37&tqId=21289&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 配置文件恢复
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> cmd = {"reset", "reset board", "board add", "board delete", "reboot backplane", "backplane abort"};
vector<string> act = {"reset what", "board fault", "where to add", "no board at all", "impossible", "install first", "unknown command"};

int main()
{
    auto match = [](string str, string s) {
        // find 函数返回匹配发生的下标位置
        return str.find(s) == 0;
    };
    
    string s;
    while (getline(cin, s))
    {
        string s1, s2;
        // 用stringstream把空格前后的字符串分开，很聪明，还不是很懂流的输入输出
        stringstream ss(s);
        ss >> s1 >> s2;
        // 输出的动作，默认未知
        int act_i = 6;
        // 如果输入只有一个字串，则只能和 cmd[0] 匹配
        if (s2.empty())
            act_i = match(cmd[0], s1) ? 0 : 6;
        // 输入两个字串
        else
        {
            bool flag = false;
            for (int i = 1; i < 6; ++i)
            {
                string first, second;
                stringstream cur_cmd(cmd[i]);
                // 通过流获得 cmd 的两个字符串
                cur_cmd >> first >> second;
                // 查看是否匹配第一个字符
                if (match(first, s1) && match(second, s2))
                {
                    if (!flag)
                    {
                        flag = true;
                        act_i = i;
                    }
                    // 匹配到多个 cmd 则输出未知
                    else
                    {
                        act_i = 6;
                        break;
                    }
                }
            }
        }
        cout << act[act_i] << endl;
    }
    
    return 0;
}