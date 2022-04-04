/** 
 * https://www.nowcoder.com/practice/e4af1fe682b54459b2a211df91a91cf3?tpId=37&tqId=21259&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 字符串加密
 * 模拟，用 vector 比 map 方便，再加个 set 方便查找
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    string key;
    string s;
    // 输入密钥，要加密的字符串
    while (cin >> key >> s)
    {
        // 密钥
        vector<char> miyao;
        // 哈希表，方便查找
        unordered_set<char> memo;
        for (int i = 0; i < key.size(); ++i)
        {
            // 转小写
            key[i] = tolower(key[i]);
            // 存不重复的字符
            if (!memo.count(key[i]))
            {
                miyao.push_back(key[i]);
                memo.insert(key[i]);
            }
        }
        // 将 A 到 Z 剩余字符存入密钥
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            if (!memo.count(ch))
                miyao.push_back(ch);
        }
        // 加密
        for (auto& ch : s)
        {
            int i = ch - 'a';
            ch = miyao[i];
        }
        cout << s << endl;
    }
    
    return 0;
}