/** 
 * https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?tpId=37&tqId=21266&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 迷宫问题
 * dfs
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> dx = {-1, 1,  0, 0};
vector<int> dy = { 0, 0, -1, 1};

vector<vector<bool>> visited;
vector<vector<int>> path;
vector<vector<int>> res;
void dfs(vector<vector<int>>& maze, int i, int j, int m, int n)
{
    // base case
    if (i == m - 1 && j == n - 1)
    {
        res = path;
        return;
    }
    
    for (int k = 0; k < 4; ++k)
    {
        int nxt_i = i + dx[k];
        int nxt_j = j + dy[k];
        // 越界判断
        if (nxt_i < 0 || nxt_i >= m || nxt_j < 0 || nxt_j >= n)
            continue;
        // 防止走回头路，跳过障碍物
        if (visited[nxt_i][nxt_j] || maze[nxt_i][nxt_j] == 1)
            continue;
        visited[nxt_i][nxt_j] = true;
        path.push_back({nxt_i, nxt_j});
        dfs(maze, nxt_i, nxt_j, m, n);
        visited[nxt_i][nxt_j] = false;
        path.pop_back();
    }
    
}

int main()
{
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> maze(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> maze[i][j];
    }
    
    visited.resize(m, vector<bool>(n, false));
    path.push_back({0, 0});
    visited[0][0] = true;
    dfs(maze, 0, 0, m, n);
    
    for (auto p : res)
        cout << "(" << p[0] << "," << p[1] << ")" << endl;
    
    return 0;
}