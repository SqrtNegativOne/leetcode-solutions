// Last updated: 07/08/2025, 12:50:57
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        std::vector<ListNode *> nodes;
        ListNode* current_node = head;
        while (current_node->next != NULL) {
            if (std::find(nodes.begin(), nodes.end(),current_node)!=nodes.end()) return true;
            else nodes.push_back(current_node);
            current_node = current_node->next;
        }
        return false;
    }
};