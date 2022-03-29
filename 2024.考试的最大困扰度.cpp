/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
/** 
 * 滑动窗口，计数窗口内的 T 个数和 F 个数，所以要两次滑动窗口
 * 可以写在一起，同时维护两个窗口
 */
#include <string>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        // 统计窗口中 T 和 F 个数
        int sumT = 0, sumF = 0;
        // 保存最大区间长度
        int resT = 0, resF = 0;
        // 左闭右开
        int leftT = 0, leftF = 0, right = 0;
        while (right < n)
        {
            if (answerKey[right] == 'T')
                sumT++;
            else
                sumF++;
            // 扩大窗口
            right++;
            // 更新结果
            if (sumT <= k)
                resT = max(resT, right - leftT);
            if (sumF <= k)
                resF = max(resF, right - leftF);
            // 收缩窗口条件
            while (sumT > k)
            {
                if (answerKey[leftT] == 'T')
                    sumT--;
                leftT++;
            }
            while (sumF > k)
            {
                if (answerKey[leftF] == 'F')
                    sumF--;
                leftF++;
            }
        }
        return max(resT, resF);
    }
};
// @lc code=end

