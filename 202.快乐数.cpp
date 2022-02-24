/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
/** 
 * 为啥一定不会出现死循环，因为int类型最大值为为 2 147 483 647
 * 所以平方和最大的数是 1 999 999 999，平方和为1 + 81*9 = 724
 * 任何数的平方和都在1到724之间，724次循环之内一定有重复的
 * [参考](https://leetcode-cn.com/problems/happy-number/solution/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/)
 * 1.hashset
 * 2.快慢指针判断环
 */
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashset;

        while (1)
        {
            // 取下一个数
            int next = GetNext(n);
            if (next == 1)
                return true;
            // 循环中出现重复
            if (hashset.count(next))
                return false;
            // 插入集合中
            hashset.insert(next);
            // 记得改变 n，也可以直接用 n 代替 next
            n = next;
        }

        return false;
    }

    // 辅函数，计算一个正整数 n 每个位置上数字的平方和
    int GetNext(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
// @lc code=end

