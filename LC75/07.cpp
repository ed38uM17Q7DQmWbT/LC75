//876. Middle of the Linked List
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* current_node = head;
        int node_count = 0;


        if (head->next == nullptr) {
            return head;
        }
        else {
            while (current_node->next != nullptr) {
                node_count++;
                current_node = current_node->next;
            }
        }


        current_node = head;
        for (int i = 0; i < (node_count + 1) / 2; i++) {
            current_node = current_node->next;
        }
        return current_node;
    }
};

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