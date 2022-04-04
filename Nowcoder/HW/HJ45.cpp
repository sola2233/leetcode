/** 
 * https://www.nowcoder.com/practice/02cb8d3597cf416d9f6ae1b9ddc4fde3?tpId=37&tqId=21268&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 名字的漂亮度
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string name;
        cin >> name;
        vector<int> cnt(26, 0);
        for (char ch : name)
            cnt[ch - 'a']++;
        // 降序排序
        sort(cnt.begin(), cnt.end(), greater<int>());
        // 贪心，出现次数最多的字母漂亮度最大
        int sum = 0, degree = 26;
        for (int num : cnt)
        {
            if (num == 0)
                break;
            sum += num * degree;
            degree--;
        }
        cout << sum << endl;
    }
    
    return 0;
}