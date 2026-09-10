//problem 1) 2265. Count Nodes Equal to Average of Subtree
class Solution {
public:
    int cnt = 0;
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto l_res = solve(root->left);
        auto r_res = solve(root->right);
        int cur_sum = root->val + l_res.first + r_res.first;
        int cur_count = 1 + l_res.second + r_res.second;
        if (cur_sum / cur_count == root->val) {
            cnt++;
        }
        return {cur_sum, cur_count};
    }
    int averageOfSubtree(TreeNode* root) {
        cnt = 0; 
        solve(root);
        return cnt;
    }
};
