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
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        // size of linked list
        int size=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            size++;
        }

        //position where first pointer will stop
        size=size-n;
        ListNode* curr=head;
        ListNode* pre=NULL;
          // Delete head
        if(size == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(size--){
            pre=curr;
            curr=curr->next;

        }
        pre->next=curr->next;
        delete curr;

        return head;
        
    }
};