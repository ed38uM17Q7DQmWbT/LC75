//328. Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)  //base case
            return nullptr;

        ListNode* a = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;

        while (odd->next && even->next)
        {
            odd->next = even->next;      //pointing odd to next odd node
            odd = odd->next;

            even->next = odd->next;      //ponting even to next even node
            even = even->next;
        }
        odd->next = a;            //linking even list to odd list 
        return head;
    }
};