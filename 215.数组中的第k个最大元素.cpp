/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
/** 
 * 方法1.小顶堆
 * 方法2.快速选择，快速排序的一种变形
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
    int findKthLargest(vector<int>& nums, int k) {
        // 目标元素下标 size - k
        int l = 0, r = nums.size() - 1, target = nums.size() - k;
        while (l < r)
        {
            int mid = quickSelection(nums, l, r);
            // 如果一趟排序后基准位置等于 target 直接返回
            if (mid == target)
                return nums[mid];
            // 如果基准位置小于 target，递归右子区间
            if (mid < target)
                l = mid + 1;
            // 如果基准位置大于 target，递归左子区间
            else 
                r = mid - 1;
        }
        return nums[l];
    }

    /**
     * 快速选择，进行快排中的一趟划分，返回基准位置（左闭右闭）
     * @return j 返回一趟划分后基准的位置
     */
    int quickSelection(vector<int>& nums, int l, int r)
    {
        // 同快排，选择 nums[l] 为基准
        int i = l + 1, j = r;
        while (true)
        {
            while (i < r && nums[i] <= nums[l])
                ++i;
            while (l < j && nums[j] >= nums[l])
                --j;
            if (i >= j)
                break;
            // 交换两个元素，使得基准两侧元素左侧比基准小，右侧比基准大
            swap(nums[i], nums[j]);
        }
        // j 最后停的位置一定是 nums[j] < nums[l]，且右边元素都比基准大，所以交换没有问题
        swap(nums[l], nums[j]);
        // 返回一趟划分后的基准位置
        return j;
    }
};
// @lc code=end

