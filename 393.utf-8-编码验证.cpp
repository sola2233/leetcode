/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
/** 
 * 模拟题
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bit_one_num = 0; // 二进制 1 的个数
        for (int num : data)
        {
            // 计算字符长度，1 到 4 字节
            if (bit_one_num == 0)
            {
                if (num >> 3 == 0b11110)
                    bit_one_num = 3;
                else if (num >> 4 == 0b1110)
                    bit_one_num = 2;
                else if (num >> 5 == 0b110)
                    bit_one_num = 1;
                else if (num >> 7 != 0b0)
                    return false;
            }
            // 匹配后面字节的前两位
            else
            {
                if (num >> 6 == 0b10)
                    bit_one_num--;
                else
                    return false;
            }
        }
        // 最后如果二进制 1 的个数为 0 则是有效 utf-8 编码
        return bit_one_num == 0;
    }
};
// @lc code=end

