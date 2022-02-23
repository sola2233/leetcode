/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

// @lc code=start
/** 
 * 数组 + hash
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class RandomizedCollection {
public:
    // nums 储存元素
    vector<int> nums;
    // val2index 储存键值对，重复元素下标用 unordered_set 存储是为了删除时快速获得索引
    unordered_map<int, unordered_set<int>> val2index;
    RandomizedCollection() {

    }
    
    bool insert(int val) {
        // 插入到 nums 尾部
        nums.push_back(val);
        // 更新 val2index
        val2index[val].insert(nums.size() - 1);
        // 判断是否存在
        bool is_not_in = (val2index[val].size() == 1);
        return is_not_in;
    }
    
    bool remove(int val) {
        // 判断是否存在
        if (!val2index.count(val))
            return false;
        // 更新 nums，交换 val 到尾部，并删除
        int index = *(val2index[val].begin());
        nums[index] = nums.back(); // 不用交换了，直接覆盖
        nums.pop_back();
        // 更新 val2index，更新原先 nums 尾部元素索引，删除 val 的索引
        val2index[nums[index]].erase(nums.size()); // 删除原先尾部元素索引
        val2index[val].erase(index); // 删除 val 的索引，可能有多个
        if (index < nums.size()) // 更新尾部元素索引，如果 val 就是最后一个元素，则不能再次添加索引
            val2index[nums[index]].insert(index);
        if (val2index[val].size() == 0) // 检查 val 是否还存在
            val2index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

