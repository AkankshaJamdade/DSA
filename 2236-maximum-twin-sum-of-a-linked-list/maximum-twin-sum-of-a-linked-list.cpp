class Solution {
public:
    int pairSum(ListNode* head) {
        
        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Find maximum twin sum
        ListNode* first = head;
        ListNode* second = prev;

        int maxSum = 0;

        while(second != NULL) {
            int sum = first->val + second->val;
            maxSum = max(maxSum, sum);

            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};