class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }

        // Find size
        int size = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        // Find kth node from beginning
        ListNode* start = head;
        for (int i = 1; i < k; i++) {
            start = start->next;
        }

        // Find kth node from end
        ListNode* end = head;
        int steps = size - k;

        while (steps--) {
            end = end->next;
        }

        swap(start->val, end->val);

        return head;
    }
};