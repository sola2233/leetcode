/** 
 * https://www.nowcoder.com/practice/f9a4c19050fc477e9e27eb75f3bfd49c?tpId=37&tqId=21264&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 称砝码
 * 哈希表去重
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> m(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> m[i];
    vector<int> x(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    
    // 存放砝码
    unordered_set<int> set;
    // 0 重量也算一种
    set.insert(0);
    // 依次放入每种重量的砝码
    for (int i = 0; i < n; ++i)
    {
        // 每种重量的砝码有 x[i] 个
        for (int j = 0; j < x[i]; ++j)
        {
            unordered_set<int> tmp(set);
            // 对已经得到的所有砝码重量，都加上 m[i]，利用 set 去重
            for (auto it = tmp.begin(); it != tmp.end(); ++it)
                set.insert(*it + m[i]);    
        }
    }
    cout << set.size() << endl;
    
    return 0;
}