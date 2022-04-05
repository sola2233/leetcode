/** 
 * 华为 3.30 号笔试题
 * https://www.nowcoder.com/discuss/919142?type=post&order=hot&pos=&page=1&ncTraceId=&channel=-1&source_id=search_post_nctrack&gio_id=F02538C54967D46F5DDE001FE311B41A-1649151682128
 * 给一个地图的长宽，给起点和终点的坐标，给障碍物个数和坐标，求最短路径长度和个数
    输入：
    5 5
    0 1
    3 3
    1
    1 2
    输出：
    5 4

    写的有问题，hhh
 */
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> memo;
int min_len = INT32_MAX;
int cnt = 0;
int dp(vector<vector<int>> &obstacleGrid, int i, int j, int i_start, int j_start, int step)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    // 越界或有障碍物
    if (i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] == 1)
        return 0;
    // base case
    if (i == i_start && j == j_start)
    {
        memo[i][j] = 1;
        if (step < min_len)
        {
            min_len = step;
            cnt = 0;
        }
        cnt++;
        return 1;
    }
    if (memo[i][j] > 0)
        return memo[i][j];

    int upper = dp(obstacleGrid, i - 1, j, i_start, j_start, step + 1);
    int left = dp(obstacleGrid, i, j - 1, i_start, j_start, step + 1);
    int res = upper + left;

    memo[i][j] = res;
    return res;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int i_start, j_start;
    cin >> i_start >> j_start;
    int i_final, j_final;
    cin >> i_final >> j_final;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int ii, jj;
        cin >> ii >> jj;
        grid[ii][jj] = 1;
    }

    // 备忘录
    memo.resize(m, vector<int>(n, 0));
    int res = dp(grid, i_final, j_final, i_start, j_start, 0);
    cout << min_len << " " << res << endl;

    return 0;
}
