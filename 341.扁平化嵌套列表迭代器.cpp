/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/** 
 * 两种思路：
 * 1.dfs，递归地遍历，将所有元素先展开，放到一个 vector 中
 * 2.栈
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// class NestedInteger {
//   public:
//     bool isInteger() const;
//     int getInteger() const;
//     const vector<NestedInteger> &getList() const;
// };
#include <list>
#include <vector>
using namespace std;
class NestedIterator {
private:
    list<NestedInteger> list_;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // 初始化将所有元素存到 list_ 中
        list_.assign(nestedList.begin(), nestedList.end());
    }
    
    int next() {
        // 先调用 hasNext 保证了第一个数一定是整数
        int res = list_.front().getInteger();
        list_.pop_front(); // 弹出第一个元素
        return res;
    }
    
    bool hasNext() {
        // 循环拆分列表元素，直到列表第一个元素是整数类型
        while (!list_.empty() && !list_.front().isInteger())
        {
            // 当 list 开头是一个列表类型时，进入循环
            vector<NestedInteger> first(list_.front().getList());
            list_.pop_front(); // 弹出第一个元素
            // 将第一个列表 first 打平并按顺序加入 list_
            int n = first.size();
            for (int i = n - 1; i >= 0; --i)
                list_.push_front(first[i]);
        }

        return !list_.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

