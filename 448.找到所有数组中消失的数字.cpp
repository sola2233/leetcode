/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
/** 
 * 很容易想到用 hashmap 记录，然后再遍历一遍找没有出现过的数字
 * 为了达到 o(1) 空间复杂度，只能把原数组作为哈希表
 * 对一个数 num，把 nums[num - 1] 加上 n
 * 这样最后再遍历一遍，哪个数小于等于 n，则下标 i + 1 没有出现
 * 注意第一遍遍历时，遍历到的数可能已经加了 n，所以要取模
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums)
            nums[(num - 1) % n] += n;

        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= n)
                res.push_back(i + 1);
        }
        return res;
    }
};
// @lc code=end

