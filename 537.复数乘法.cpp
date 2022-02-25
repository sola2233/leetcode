/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
#include <regex>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // \转义了两次，一次得到 \,一次得到 +，意思是匹配 + 或 i
        regex re("\\+|i");
        // -1 表示按 re 分割字符串
        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), sregex_token_iterator());
        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), sregex_token_iterator());
        // 计算实部和虚部
        int real1 = stoi(complex1[0]);
        int imag1 = stoi(complex1[1]);
        int real2 = stoi(complex2[0]);
        int imag2 = stoi(complex2[1]);
        int real = real1 * real2 - imag1 * imag2;
        int imag = real1 * imag2 + imag1 * real2;

        return to_string(real) + "+" + to_string(imag) + "i";
    }
};
// @lc code=end

