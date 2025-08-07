// Last updated: 07/08/2025, 12:51:01
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
    int max_path_sum;

    int maxPathSum(TreeNode* root) {
        max_path_sum = INT_MIN;
        single_branch(root);
        return this->max_path_sum;
    }

    int single_branch(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = std::max(0, single_branch(root->left));
        int right = std::max(0, single_branch(root->right));

        this->max_path_sum = std::max(max_path_sum, left+(root->val)+right);

        return (root->val) + std::max(left, right);
    }
};