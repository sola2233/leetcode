/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
/** 
 * 数组+hash
 * 动态数组存储元素值
 * 哈希表存储存储值到索引的映射。
 */
#include <vector>
#include <unordered_map>
using namespace std;
class RandomizedSet {
public:
    // 存储元素的值
    vector<int> nums;
    // 记录每个元素对应在 nums 中的索引
    unordered_map<int,int> val2index;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        // 已存在返回 false
        if (val2index.count(val))
            return false;
        // 不存在则插入到 nums 尾部
        nums.push_back(val);
        // 更新 val2index
        val2index[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        // 不存在返回 false
        if (!val2index.count(val))
            return false;
        // 更新 nums，val 和尾部元素交换，删除 nums 尾部元素
        int index = val2index[val];
        swap(nums[index], nums.back());
        nums.pop_back();
        // 更新 val2index，更新 nums 尾元素的索引，删除 val 的索引
        val2index[nums[index]] = index;
        val2index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

