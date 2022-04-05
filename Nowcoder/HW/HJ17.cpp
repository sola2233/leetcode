/** 
 * https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29?tpId=37&tqId=21240&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 坐标移动
 * 参考了题解中的写法，字符串分割参考了 C++ Primer 中的写法
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
        // 初始位置
        int x = 0, y = 0;
        // split 字符串，通过不断找 ; 来分割
        int index = 0;
        string::size_type pos = 0;
        while ((pos = s.find(';', pos)) != string::npos)
        {
            string tmp = s.substr(index, pos - index);
            // 判断 tmp 是否合法
            if ((tmp.size() == 2 && isdigit(tmp[1])) || 
                (tmp.size() == 3 && isdigit(tmp[1]) && isdigit(tmp[2])) )
            {
                // (x, y): 这里 x 是列，y 是行，坐标系就是普通的笛卡尔坐标系，不是图像坐标系
                switch(tmp[0])
                {
                    case 'A':
                        x -= stoi(tmp.substr(1));
                        break;
                    case 'D':
                        x += stoi(tmp.substr(1));
                        break;
                    case 'W':
                        y += stoi(tmp.substr(1));
                        break;
                    case 'S':
                        y -= stoi(tmp.substr(1));
                        break;
                    default:
                        break;
                }
            }
            pos++;
            index = pos;
        }
        cout << x << "," << y << endl;
    }
    
    return 0;
}