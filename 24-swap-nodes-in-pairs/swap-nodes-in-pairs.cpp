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
    ListNode* swapPairs(ListNode* head) {
         if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* pre = dummy;

    while (pre->next != NULL && pre->next->next != NULL) {

        ListNode* first = pre->next;
        ListNode* second = first->next;

        // Swap the two nodes
        pre->next = second;
        first->next = second->next;
        second->next = first;

        // Move to the next pair
        pre = first;
    }

    return dummy->next;
        
    }
};