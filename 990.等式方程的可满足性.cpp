/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
/** 
 * 并查集
 */
#include <vector>
#include <string>
using namespace std;
class UF
{
private:
    // 连通分量个数
    int count;
    // 记录每个节点的父节点，记录一棵树
    vector<int> parent;
    // 记录树的重量
    vector<int> size;
public:
    UF(int n)
    {
        // 初始化
        count = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // 将节点 index1 和 index2 连通
    void Union(int index1, int index2)
    {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if (root1 == root2)
            return;
        
        // root1 大，root2 小
        if (size[root1] > size[root2])
        {
            // root2 接到 root1 上
            parent[root2] = root1;
            size[root1] += size[root2];
        }
        else
        {
            // root1 接到 root2 上
            parent[root1] = root2;
            size[root2] += size[root1];
        }
        // 两个连通分量合并为一个
        --count;
    }

    // 返回节点 x 连通分量的根节点
    int Find(int x)
    {
        while (parent[x] != x)
        {
            // 路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    // 判断节点 index1 和 index2 是否连通
    bool Connected(int index1, int index2)
    {
        int root1 = Find(index1);
        int root2 = Find(index2);

        return root1 == root2;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // 建立并查集，26 个英文字符
        UF uf(26);
        // 使等式两端的字母节点连通，形成连通分量
        for (string str : equations)
        {
            int x = str[0] - 'a';
            int y = str[3] - 'a';
            if (str[1] == '=')
            {
                uf.Union(x, y);
            }
        }
        // 检查不等关系是否打破相等关系的连通性
        for (string str : equations)
        {
            int x = str[0] - 'a';
            int y = str[3] - 'a';
            if (str[1] == '!')
            {
                // 如果相等关系成立，就是逻辑冲突
                if(uf.Connected(x, y))
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end

