/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/** 
 * 方法1.前序遍历
 * 方法2.后序遍历
 * 方法3.利用 bst 的特性，空节点不序列化，详细看题解吧
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
#include <list> // 还原时比较有用，从头结点删除比 vector 快
using namespace std;
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        traverse(root, res);

        return res;
    }

    void traverse(TreeNode* root, string& res)
    {
        // base case
        if (root == nullptr)
        {
            res += "#,";
            return;
        }
        // 前序位置序列化
        res += to_string(root->val) + ",";
        traverse(root->left, res);
        traverse(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 先按 , 分割成字符串
        list<string> bintree = split(data);
        // 构建 BST
        TreeNode* root = buildBST(bintree);

        return root;
    }

    // list 容器必须是引用，因为每次递归都要修改 data
    TreeNode* buildBST(list<string>& data)
    {
        // 找到根节点，并移除
        string root_val = data.front();        
        data.pop_front();
        // base case，能够保证遍历一定是以 “#” 结尾的，所以不会再往下递归，不会出现list空
        if (root_val == "#")
            return nullptr;
        
        TreeNode* root = new TreeNode(stoi(root_val));
        // 递归构建子树
        root->left = buildBST(data);
        root->right = buildBST(data);

        return root;
    }

    list<string> split(string data)
    {
        list<string> res;
        string ans; // 保存每个节点值
        for (auto& ch : data)
        {
            // 找到一个节点
            if (ch == ',')
            {
                res.push_back(ans);
                ans.clear();
                continue;
            }
            // 否则把当前字符加到尾部
            ans.push_back(ch);
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

