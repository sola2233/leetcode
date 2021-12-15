/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
/** 
 * 快速选择，快速排序的一种变形
 * 参考https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
 * 每次经过「划分」操作后，我们一定可以确定一个元素的最终位置；
 * 并且可以保证该元素左边的元素小于它，右边的元素大于它；
 * 所以只要某次划分的得到的元素位置 q 为倒数第 k 个下标的时候，就已经找到了答案。
 * 算法步骤：
 * 在分解的过程当中，对子数组进行划分，如果划分得到的 q 正好就是我们需要的下标，就直接返回 a[q]；
 * 否则，如果 q 比目标下标小，就递归右子区间，否则递归左子区间。
 * 这样就可以把原来递归两个区间变成只递归一个区间，提高了时间效率。这就是「快速选择」算法。
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * 寻找数组nums中第k大元素 
     * @return 第k大元素的值
     */
    int findKthLargest(vector<int>& nums, int k) {
        // 目标元素下标 size - k
        int l = 0, r = nums.size() - 1, target = nums.size() - k;
        while (l < r)
        {
            int mid = quickSelection(nums, l, r);
            if (mid == target)
                return nums[mid];
            if (mid < target)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return nums[l];
    }

    /**
     * 辅助函数 快速选择 
     * @param 
     * @return 
     */
    int quickSelection(vector<int>& nums, int l, int r)
    {
        int i = l + 1, j = r;
        while (true)
        {
            while (i < r && nums[i] <= nums[l])
                ++i;
            while (l < j && nums[j] >= nums[l])
                --j;
            if (i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
};
// @lc code=end

