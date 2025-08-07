// Last updated: 07/08/2025, 12:51:40
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* answer = dummy_head;
        int carry = 0;
        while (l1 != nullptr or l2 != nullptr or carry != 0) {
            int current_sum = carry;
            if (l1 != nullptr) {
                current_sum += l1->val;
                l1 = l1->next;
            } 
            if (l2 != nullptr) {
                current_sum += l2->val;
                l2 = l2->next;    
            }
            if (current_sum > 9) {
                carry = 1;
                current_sum -= 10;
            } else carry = 0;
            answer->next = new ListNode(current_sum);
            answer = answer->next;
        }

        ListNode* result = dummy_head->next;
        delete dummy_head;
        return result;
    }
};