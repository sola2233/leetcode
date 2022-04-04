/** 
 * https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&tqId=21282&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 找出字符串中第一个只出现一次的字符
 * 方法1.模拟，哈希表加快查找速度
 * 因为哈希表存放没有顺序，所以用一个列表存放结果，方便删除重复的字符，但是 find 要 o(n) 时间
 * 方法2.
 * 字符串 find_first_of == find_last_of 则这个数只出现过一次
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        // 保存遍历过的字符
        unordered_set<char> set;
        // 保存所有只出现过一次的字符，按出现顺序存放
        list<char> res;
        for (int i = 0; i < s.size(); ++i)
        {
            // 如果遇到已经在结果集里的字符，从结果集删除
            if (find(res.begin(), res.end(), s[i]) != res.end())
                res.remove(s[i]);
            // 如果当前字符没有遍历过，加入结果集
            if (!set.count(s[i]))
                res.push_back(s[i]);
            // 保存遍历过得字符
            set.insert(s[i]);
        }
        // 结果集为空时不存在符合条件的字符
        if (res.empty())
            cout << -1 << endl;
        else
            cout << *res.begin() << endl;
    }
    
    return 0;
}