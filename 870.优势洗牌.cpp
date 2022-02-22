/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
/** 
 * 数组，排序 + 双指针
 * 1.排序 nums1 和 nums2
 * 2.对 nums2 中最大的，如果 nums1 中有能比得过的，就比，否则就用最小的去摆烂
 * 3.之后从 nums2 和 nums1 中删除刚刚的两个数，继续重复 2
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // 从小到大排序，nums2 要加上索引排序
        int n = nums1.size();
        vector<pair<int, int>> nums_b;
        for (int i = 0; i < n; ++i)
            nums_b.push_back(make_pair(i, nums2[i]));
        sort(nums1.begin(), nums1.end());
        sort(nums_b.begin(), nums_b.end(), [](auto& num1, auto& num2) -> bool {
            return num1.second < num2.second;
        });

        vector<int> res(n);
        // nums1 的双指针
        int left = 0, right = n - 1;
        // 从大到小遍历 nums2 
        for (int i = n - 1; i >= 0; --i)
        {
            int index = nums_b[i].first, max_val = nums_b[i].second;
            // 对 nums2 中最大的，如果 nums1 中有能比得过的，就比
            if (nums1[right] <= max_val)
                res[index] = nums1[left++];
            // 否则就用最小的去摆烂
            else if (nums1[right] > max_val)
                res[index] = nums1[right--];
        }

        return res;
    }
};
// @lc code=end

