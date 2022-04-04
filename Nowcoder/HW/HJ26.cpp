/** 
 * https://www.nowcoder.com/practice/5190a1db6f4f4ddb92fd9c365c944584?tpId=37&tqId=21249&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 字符串排序
 * 哈希，每个字母按出现的先后顺序存起来，用 vector 代替 hash
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        vector<vector<char>> memo(26);
        for (int i = 0; i < s.size(); ++i)
        {
            // 是字母就存起来
            if (isalpha(s[i]))
            {
                int pos = tolower(s[i]) - 'a';
                memo[pos].push_back(s[i]);
            }
        }
        // 修改原字符串
        int pos = 0;
        for (int i = 0; i < 26; ++i)
        {
            int sz = memo[i].size();
            for (int j = 0; j < sz; )
            {
                // 是字母才处理，特殊字符跳过
                if (isalpha(s[pos]))
                {
                    s[pos] = memo[i][j];
                    ++j;
                    ++pos;
                }
                // 不是字母字符串指针递增
                else
                    ++pos;
            }
        }
        
        cout << s << endl;
    }
    
    return 0;
}