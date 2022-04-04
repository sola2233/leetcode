/** 
 * https://www.nowcoder.com/practice/fbc417f314f745b1978fc751a54ac8cb?tpId=37&tqId=21290&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 24点游戏算法
 * 回溯，dfs
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> visited;
vector<double> path;
bool flag;
void dfs(vector<double>& nums, double sum)
{
    // base case
    if (path.size() == 4)
    {
        if (sum == 24)
            flag = true;
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        // 剪枝
        if (flag)
            break;
        // 去重
        if (visited[i])
            continue;
        visited[i] = true;
        path.push_back(i);
        dfs(nums, sum + nums[i]);
        dfs(nums, sum - nums[i]);
        dfs(nums, sum * nums[i]);
        dfs(nums, sum / nums[i]);
        visited[i] = false;
        path.pop_back();
    }
}

int main()
{
    vector<double> nums(4, 0);
    while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3])
    {
        visited.resize(4, false);
        flag = false;
        dfs(nums, 0);
        if (flag)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    
    return 0;
}