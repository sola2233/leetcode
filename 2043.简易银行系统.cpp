/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 *
 * [2043] 简易银行系统
 */

// @lc code=start
#include <vector>
using namespace std;
class Bank {
public:
    vector<long long> balance_;
    Bank(vector<long long>& balance) {
        balance_ = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        int n = balance_.size();
        // 编号账户不存在
        if (account1 > n || account2 > n)
            return false;
        // 钱不够
        if (balance_[account1 - 1] < money)
            return false;
        // 转账
        balance_[account1 - 1] -= money;
        balance_[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        int n = balance_.size();
        // 编号账户不存在
        if (account > n)
            return false;
        balance_[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        int n = balance_.size();
        // 编号账户不存在
        if (account > n)
            return false;
        // 钱不够
        if (balance_[account - 1] < money)
            return false;
        // 取钱
        balance_[account - 1] -= money;
        return true;        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end

