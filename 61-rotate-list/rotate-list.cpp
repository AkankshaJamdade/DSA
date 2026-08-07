class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length
        int n = 1;
        ListNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
            n++;
        }

        // Reduce k
        k = k % n;

        if (k == 0)
            return head;

        int cut = n - k;

        ListNode* curr = head;
        ListNode* pre = NULL;

        while (cut--) {
            pre = curr;
            curr = curr->next;
        }

        pre->next = NULL;

        ListNode* newHead = curr;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = head;

        return newHead;
    }
};