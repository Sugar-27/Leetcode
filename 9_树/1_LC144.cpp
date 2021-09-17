// 前序遍历二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        find(root);
        return ans;
    }

private:
    void find(TreeNode* root) {
        if (root == nullptr)    return;
        ans.push_back(root->val);
        find(root->left);
        find(root->right);
    }

    vector<int> ans;
};