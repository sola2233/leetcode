/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
/** 
 * 最小生成树
 * 用并查集 + kruskal
 * 1.先生成所有边以及权重
 * 2.按权重大小非降序排序所有边
 * 3.依次将每条边加入最小生成树，如果成环，则跳过这条边（用并查集判断）
 */
#include <vector>
#include <queue>
#include <algorithm>
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

    int Count()
    {
        return count;
    }
};

class Solution {
public:
    // // 优先级队列比较函数
    // struct MyCompare
    // {
    //         bool operator() (const vector<int>& a, const vector<int>& b)
    //     {
    //         return a[2] > b[2];
    //     };
    // };
    // // 记录节点 i 是否在 mst 中
    // vector<bool> is_mst;
    // // 优先级队列，记录每条横切边
    // priority_queue<vector<int>, vector<vector<int>>, MyCompare> pq;
    // // 图，保存每个节点相邻的边，因为一条边用 vector<int> 来表示，包括边的两个节点和权重，所以有三层vector
    // vector<vector<vector<int>>> graph;

    // // 方法2.Prim 算法
    // int minCostConnectPoints(vector<vector<int>>& points) {
    //     // 分配内存
    //     int n = points.size();
    //     graph.resize(n);
    //     is_mst.resize(n);
    //     // 生成所有边及权重的邻接表
    //     for (int i = 0; i < n; ++i)
    //     {
    //         for (int j = i + 1; j < n; ++j)
    //         {
    //             int xi = points[i][0], yi = points[i][1];
    //             int xj = points[j][0], yj = points[j][1];
    //             // 计算曼哈顿距离
    //             int dist = abs(xi - xj) + abs(yi - yj);
    //             // 和 Kruskal 方法里的不太一样，这个是邻接表，要记录每个节点的邻边
    //             // Kruskal 里只要得到所有边就行了，那个是边集
    //             graph[i].push_back({i, j, dist});
    //             graph[j].push_back({j, i, dist});
    //         }
    //     }

    //     /** Prim 算法 */
    //     int mst = 0;
    //     // 随便从一个点开始切分都可以，不妨从节点 0 开始
    //     is_mst[0] = true;
    //     cut(0);
    //     while (!pq.empty())
    //     {
    //         // 取出队列首位置的最小横切边
    //         vector<int> edge = pq.top();
    //         pq.pop();
    //         int to = edge[1], weight = edge[2];
    //         // 如果相邻节点 to 已经在 mst 中，跳过，否则会产生环
    //         if (is_mst[to])
    //             continue;
    //         // 否则将 edge 加入 mst
    //         mst += weight;
    //         is_mst[to] = true;
    //         // 节点 to 加入后，进行新一轮切分，会产生更多横切边
    //         cut(to);
    //     }

    //     return mst;
    // }

    // // 对节点 s 做一次切分
    // void cut(const int& s)
    // {
    //     for (auto edge : graph[s])
    //     {
    //         int to = edge[1];
    //         // 相邻接点 to 已经在最小生成树中，跳过
    //         // 否则这条边会产生环
    //         if (is_mst[to])
    //             continue;
    //         // 加入横切边队列
    //         pq.push(edge);
    //     }
    // }

    // 方法1.Kruskal 算法
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 先生成所有边及权重
        int n = points.size();
        vector<vector<int>> edges;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int xi = points[i][0], yi = points[i][1];
                int xj = points[j][0], yj = points[j][1];
                // 计算曼哈顿距离
                int dist = abs(xi - xj) + abs(yi - yj);
                edges.push_back({i, j, dist});
            }
        }
        // 按权重非降序排序
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[2] < b[2];
        });

        // 建立并查集，判断是否成环
        UF uf(n);
        int mst = 0;
        // 依次将边添加进最小生成树
        for (auto edge : edges)
        {
            // 如果添加成环，跳过这条边
            if (uf.Connected(edge[0], edge[1]))
                continue;
            // 若不会成环，则属于最小生成树
            uf.Union(edge[0], edge[1]);
            mst += edge[2];
        }

        return mst;
    }
};
// @lc code=end

