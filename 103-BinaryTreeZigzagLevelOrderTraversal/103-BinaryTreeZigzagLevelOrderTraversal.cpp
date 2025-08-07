// Last updated: 07/08/2025, 12:51:08
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

class Node {
public:
    TreeNode* tree_node;
    int level;

    Node(TreeNode* tree_node, int level) {
        this->tree_node = tree_node;
        this->level = level;
    }
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<Node> frontier; // BFS
        vector<vector<int>> levels = {};

        frontier.push(Node(root, 1));

        while (!frontier.empty()) {

            // Take and remove node from frontier.
            Node current_node = frontier.front();
            frontier.pop();

            if (current_node.tree_node == nullptr)
                continue;

            while (current_node.level > levels.size())
                levels.push_back({});
            
            levels[current_node.level-1].push_back(current_node.tree_node->val);

            // Expand node
            frontier.push(Node(current_node.tree_node->left,  current_node.level+1));
            frontier.push(Node(current_node.tree_node->right, current_node.level+1));
        }

        for (int level_index = 1; level_index < levels.size(); level_index += 2)
            reverse(levels[level_index].begin(), levels[level_index].end());

        return levels;
    }
};