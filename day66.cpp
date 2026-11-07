//problem 1) 101. Symmetric Tree
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
    TreeNode* mirror(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* node = new TreeNode(root->val);

        node->left = mirror(root->right);
        node->right = mirror(root->left);

        return node;
    }
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
    
        return p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        TreeNode* temp = mirror(root);
        return isSame(root, temp);
    }
};