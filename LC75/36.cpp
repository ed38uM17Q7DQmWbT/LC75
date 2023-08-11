//19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* hi = head;
        ListNode* lo = head;
        for (int i = 0; i < n; i++) {
            hi = hi->next;
        }
        if (!hi) {
            return head->next;
        }
        while (hi->next) {
            hi = hi->next;
            lo = lo->next;
        }
        lo->next = lo->next->next;
        return head;
    }
};