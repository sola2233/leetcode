/** 
 * https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId=37&tqId=21287&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * MP3光标位置
 * 模拟
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void parseCMD(char cmd, int& pos, int& left, int& right, int n)
{
    // 歌曲小于等于 4
    if (n <= 4)
    {
        if (cmd == 'U')
            pos = (pos - 1) % right;
        else if (cmd == 'D')
            pos = (pos + 1) % right;
        
        return;
    }
    
    // 光标向上
    if (cmd == 'U')
    {
        // 光标在最上面
        if (pos == 0)
        {
            // 特殊翻页
            if (left == 1)
            {
                left = n - 3;
                right = n;
                pos = 3;
            }
            // 一般翻页
            else
            {
                left--;
                right--;
            }
        }
        // 普通光标移动
        else
            pos--;
    }
    // 光标向下
    else if (cmd == 'D')
    {
        // 光标在最下面
        if (pos == 3)
        {
            // 特殊翻页
            if (right == n)
            {
                left = 1;
                right = 4;
                pos = 0;
            }
            // 一般翻页
            else
            {
                left++;
                right++;
            }
        }
        // 普通光标移动
        else
            pos++;
    }
}

int main()
{
    int n;
    string cmd;
    while (cin >> n >> cmd)
    {
        // 屏幕窗口，用双指针表示
        int left = 1, right = min(4, n);
        // 光标在窗口内的相对位置
        int pos = 0;
        for (char ch : cmd)
        {
            // 解析命令
            parseCMD(ch, pos, left, right, n);
        }
        
        for (int i = left; i <= right; ++i)
            cout << i << " ";
        cout << endl;
        cout << (left + pos) << endl;
    }
    
    return 0;
}