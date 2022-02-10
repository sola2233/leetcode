/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
/** 
 * 二分查找
 * 分解一下问题，就是找到左边界和右边界，统一用左闭右闭
 * 1.Q:对寻找左右边界的理解：为什么找左边界返回 left，找右边界返回 right
 *   A:关键在于算法的 不变性 和 单调性
 *     单调性：随着算法不断运行，规模递减，这是单调性
 *     不变性：以找左边界为例，不考虑 target 不在 nums 中的情况，
 *            nums[left] 左侧的数一定小于 target，所以 target 必不可能在 nums[left] 左侧
 *            而 nums[right] 一定大于等于 target，算法最后搜索区间只有一个数时，left == right，
 *            此时 nums[right] 一定小于 target，而 num[left] 大于等于 target
 *            所以只能分情况讨论，返回 left 或者 -1
 * 2.Q:为什么越界检查只检查 left 和 right 中的一个值就行了
 *   A:虽然 left 和 right 都有可能越界，最后只检查 left 的越界情况是因为我们要返回的是 left，
 *     在返回之前还要检查 nums[left] 是否等于 target，所以要检查 left 是否越界。
 * 3.Q:为什么最后还要判断 nums[left] 是否等于 target
 *   A:left 有四种情况：
 *     1.target 比 nums 所有数都小。此时 left = 0，且 nums[left] != target，返回 -1
 *     2.target 比 nums 所有数都大。此时 left = nums.size()，越界，返回 -1
 *     3.target 在 nums 中且存在。此时不会越界，nums[left] == target，且是左边界
 *     4.target 在 nums 中且不存在。此时不会越界，nums[left] > target，且左边的数都比 target 小
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 负例
        if (nums.empty()) return vector<int> {-1, -1};
        
        // 获取左右边界
        int left_bound = LeftBound(nums, target);
        int right_bound = RightBound(nums, target);

        return vector<int> {left_bound, right_bound};
    }

    // 左边界，返回 left
    int LeftBound(vector<int>& nums, int target)
    {
        // 左闭右闭
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] == target)
                right = mid - 1;
        }

        // 处理越界情况和 target 不存在情况
        if (left >= nums.size() || nums[left] != target)
            return -1;

        return left;
    }

    // 右边界，返回 right
    int RightBound(vector<int>& nums, int target)
    {
        // 左闭右闭
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] == target)
                left = mid + 1;
        }

        // 处理越界情况和 target 不存在情况
        if (right < 0 || nums[right] != target)
            return -1;
        
        return right;
    }
};
// @lc code=end

