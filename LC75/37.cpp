//234. Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        std::vector<int> v;
        ListNode* current = head;
        int node_count = 0;


        while (current != nullptr) {
            node_count++;
            v.push_back(current->val);
            current = current->next;
        }


        current = head;
        //reverse(v.begin(), v.end());
        while (current != nullptr) {
            if (current->val != v.back()) {
                return false;
            }
            v.pop_back();
            current = current->next;
        }
        return true;
    }
};