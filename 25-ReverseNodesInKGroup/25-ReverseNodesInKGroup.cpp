// Last updated: 07/08/2025, 12:51:34
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (true) {
            ListNode* temp = prev;
            for (int i = 0; i < k; ++i) {
                temp = temp->next;
                if (!temp) return dummy.next;  // Less than k nodes remain
            }

            // Reverse k nodes
            ListNode* next = prev->next, *tail = next;
            for (int i = 0; i < k - 1; ++i) {
                ListNode* move = tail->next;
                tail->next = move->next;
                move->next = prev->next;
                prev->next = move;
            }

            prev = tail;
        }
    }
};