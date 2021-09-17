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
    // 在以root为根的子树中删除key，返回新的根
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)    return nullptr;
        if (root->val == key) {
            if (root->left == nullptr) return root->right;  // 没有左子树，让right代替root的位置
            if (root->right == nullptr) return root->left;  // 没有右子树，让left代替root的位置
            TreeNode* next = root->right;
            while (next->left != nullptr)   next = next->left;  // 找后继：右子树一路向左
            root->right = deleteNode(root->right, next->val);
            root->val = next->val;
        }
        // key在树的右子树里面
        if (root->val < key)    root->right =  deleteNode(root->right, key);
        // key在树的左子树里面
        else if (root->val > key)   root->left = deleteNode(root->left, key);
        return root;
    }
};