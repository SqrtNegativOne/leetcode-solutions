// Last updated: 07/08/2025, 12:51:07
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        std::stack<std::pair<TreeNode*, int>> frontier; // To explore
        // std::unordered_set<TreeNode*> explored;
        int max_depth = 0;

        frontier.push({root, 1});

        while (!frontier.empty()) {

            auto [current_node, depth] = frontier.top();
            frontier.pop();

            if (current_node == nullptr)
                continue;

            max_depth = std::max(max_depth, depth);

            frontier.push({current_node->left, depth+1});
            frontier.push({current_node->right, depth+1});

        }

        return max_depth;
    }
};