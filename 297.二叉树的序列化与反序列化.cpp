/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/** 
 * 二叉树问题，递归
 * [参考](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/er-cha-shu-de-xu-lie-hua-yu-fan-xu-lie-h-v8ja/)
 * 序列化：
 * 关键在于如何找到根节点和左右子树的节点，不同的序列化方法，找根节点的方式也不同
 * 先说结论，中序不行，因为找不到根节点
 * 方法1.前序遍历，直接递归遍历一遍即可，无需返回值
 * 方法2.后序遍历，递归遍历，要利用子树的返回值构建序列
 * 方法3.层次遍历，利用队列，bfs
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <vector>
#include <list>
using namespace std;
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        traverse(root, res);

        return res;        
    }

    // 前序遍历
    void traverse(TreeNode* root, string& res)
    {
        // base case
        if (root == nullptr)
        {
            res += "#,";
            return;
        }

        // 前序位置，序列化，以“ ”分隔
        res += to_string(root->val) + ",";

        traverse(root->left, res);
        traverse(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // string 转成 list
        list<string> bintree;
        bintree = split(data);
        
        return build(bintree);
    }

    // 递归函数，重建二叉树
    // list 容器必须是引用，因为每次递归都要修改 data
    TreeNode* build(list<string>& data)
    {
        // 从前往后取出元素，找出根节点并删除
        string first = data.front();
        data.erase(data.begin());
        // base case，能够保证遍历一定是以 “#” 结尾的
        if (first == "#")
            return nullptr;

        // 构建根节点
        TreeNode* root = new TreeNode(stoi(first));
        
        // 递归计算左右子树
        root->left = build(data);
        root->right = build(data);

        return root;
    }

    //按逗号分割字符串，可以看看 449 的分割方式，更好
    list<string> split(string& data)
    {
        int start = 0; //初始查找位置
        list<string> res; //保存分割结果
        std::string::size_type pos; //find()函数的返回值类型
        while (1)
        {
            pos = data.find(',', start);
            // 如果没有找到，直接break，string::npos 相当于 -1
            if (pos == string::npos)
                break;
            // substr(pos, n)获取从 pos 开始的 n 个字符
            res.push_back(data.substr(start, pos - start));
            // 更新下一次查找位置
            start = pos + 1;
        }
        return res;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

