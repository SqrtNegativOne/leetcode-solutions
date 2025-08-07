// Last updated: 07/08/2025, 12:51:10
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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> frontier1;
        stack<TreeNode*> frontier2;

        frontier1.push(root->left);
        frontier2.push(root->right);

        while (frontier1.size() and frontier2.size()) {

            TreeNode* node1 = frontier1.top();
            TreeNode* node2 = frontier2.top();

            if (node1 == nullptr or node2 == nullptr) {
                if (node1== nullptr and node2 == nullptr) {
                    frontier1.pop(); frontier2.pop();
                    continue;
                }
                return false;
            }
            if (node1->val != node2->val) {
                return false;
            }
            
            frontier1.pop(); frontier2.pop();

            frontier1.push(node1->left);
            frontier1.push(node1->right);
            frontier2.push(node2->right);
            frontier2.push(node2->left);
        }
        return true;
    }
};