/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
/** 
 * 肯定不能暴力，会超时
 * 方法1.树状数组
 * 方法2.线段树
 */
#include <vector>
using namespace std;
class NumArray {
private:
    // 树状数组，保存累加和
    vector<int> m_tree;
    // 输入序列
    vector<int>& m_nums;

    // 找到 index 的二进制数的最后一个 1 所表示的二进制
    // index 不能等于 0, 否则会进入死循环, 所以树状数组通常使用的下标会执行 +1 操作
    int lowBit(int index)
    {
        return index & (-index);
    }

    // 更新树状数组，O(logn)
    void add(int index, int val)
    {
        while (index < m_tree.size())
        {
            // 累加和数组 m_trees
            m_tree[index] += val;
            // 寻找被影响的数组下标
            index += lowBit(index);
        }
    }

    // 查询前 index 个数的和，O(logn)
    int prefixSum(int index)
    {
        int sum = 0;
        while (index > 0)
        {
            sum += m_tree[index];
            // 查询树状数组时使用 index -= lowBit(index) 来寻找小于 index 的下一个区间
            index -= lowBit(index);
        }
        return sum;
    }

public:
    // 构造树状数组，O(nlogn)
    NumArray(vector<int>& nums) : m_nums(nums) {
        // 构造树状数组
        m_tree.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
            add(i + 1, nums[i]);
    }
    
    void update(int index, int val) {
        // 修改前缀和
        add(index + 1, val - m_nums[index]);
        // 修改输入数组
        m_nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

