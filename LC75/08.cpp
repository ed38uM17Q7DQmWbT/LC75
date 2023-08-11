//142. Linked List Cycle II
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        vector <ListNode*> sequence;
        while (head != nullptr) {
            for (int i = 0; i < sequence.size(); i++) {
                if (sequence[i] == head)
                    return head;
            }
            sequence.push_back(head);
            head = head->next;
        }
        return nullptr;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */