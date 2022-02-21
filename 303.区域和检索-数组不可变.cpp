/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
/** 
 * 数组题，前缀和
 * presum[i] 表示 nums[0] + ... + nums[i - 1]
 * 不包括自身比较好，这样可以不用储存 nums 数组本身就能算出所有范围和
 */
#include <vector>
using namespace std;
class NumArray {
public:
    vector<int> pre_sum;

    NumArray(vector<int>& nums) {
        // 分配内存
        int n = nums.size();
        pre_sum.resize(n + 1); // 需要多分配一个空间
        // 计算前缀和
        pre_sum[0] = 0; // 可以不用加，已经初始化为 0 了
        for (int i = 1; i < n + 1; ++i)
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

