/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
#ifndef HTC // 枚举 ax + by + c = 0 的 a，b，c，写的有问题
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        // 2 个点以内总可以用一条直线连起来
        if (n <= 2)
            return n;
        // 记录出现次数最多的直线，一次循环中
        int cnt = 0;
        for (int i = 0; i < points.size() - 1; ++i)
        {
            // mp 要放到循环里面，因为需要找每次循环中经过点最多的直线
            map<vector<double>, int> mp;
            for (int j = i + 1; j < points.size(); ++j)
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                double a = 0, b = 0, c = 0;
                if (x2 == x1)
                {
                    a = 1;
                    b = 0;
                    c = -x1;

                }
                else if (y2 == y1)
                {
                    a = 0;
                    b = 1;
                    c = -y1;
                }
                else
                {
                    a = y2 - y1;
                    b = -(x2 - x1);
                    c = x2 * y1 - x1 * y2;
                    if (a < 0)
                    {
                        a = -a;
                        b = -b;
                        c = -c;
                    }
                    b = b / a;
                    c = c / a;
                    a = 1;
                }
                vector<double> tmp = {a,b,c};
                mp[tmp]++;
                cnt = max(cnt, mp[tmp] + 1);
            }
        }
        return cnt;
    }
#endif

    // int gcd(int a, int b) 
    // {
    //     return b ? gcd(b, a % b) : a;
    // }

    // int maxPoints(vector<vector<int>>& points) 
    // {
    //     int n = points.size();
    //     // 2 个点以内总可以用一条直线连起来
    //     if (n <= 2)
    //         return n;
    //     int ret = 0;
    //     for (int i = 0; i < n; i++) 
    //     {
    //         if (ret >= n - i || ret > n / 2)
    //             break;
    //         unordered_map<int, int> mp;
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             int x = points[i][0] - points[j][0];
    //             int y = points[i][1] - points[j][1];
    //             if (x == 0)
    //                 y = 1;
    //             else if (y == 0)
    //                 x = 1;
    //             else 
    //             {
    //                 if (y < 0) 
    //                 {
    //                     x = -x;
    //                     y = -y;
    //                 }
    //                 int gcdXY = gcd(abs(x), abs(y));
    //                 x /= gcdXY, y /= gcdXY;
    //             }
    //             mp[y + x * 20001]++;
    //         }
    //         int maxn = 0;
    //         for (auto& [_, num] : mp)
    //             maxn = max(maxn, num + 1);
    //         ret = max(ret, maxn);
    //     }
    //     return ret;
    // }

};
// @lc code=end

