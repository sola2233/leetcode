/** 
 * https://www.nowcoder.com/practice/ebe941260f8c4210aa8c17e99cbc663b?tpId=37&tqId=21292&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
 * 矩阵乘法
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    // 输入矩阵 A(x, y)
    vector<vector<int>> matrix_a(x, vector<int>(y, 0));
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            cin >> matrix_a[i][j];
    // 输入矩阵 B(y, z)
    vector<vector<int>> matrix_b(y, vector<int>(z, 0));
    for (int i = 0; i < y; ++i)
        for (int j = 0; j < z; ++j)
            cin >> matrix_b[i][j];
    
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            int num = 0;
            for (int k = 0; k < y; ++k)
            {
                num += matrix_a[i][k] * matrix_b[k][j]; 
            }
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}