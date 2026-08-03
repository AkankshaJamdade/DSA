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
        ListNode* slow= head;
        ListNode* fast= head;
        if(head == NULL){
            return true;
        }

        //get middle one
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        

        //reverse second half
        ListNode* head1;
        ListNode* curr=slow;
        ListNode* fut=NULL;
        ListNode* pre=NULL;
        while(curr){
            fut=curr->next;
            curr->next=pre;
            pre=curr;
            curr=fut;

        }
        head1=pre;
       

        //comparison
        
        while(head1 !=NULL){
            if(head->val != head1->val){
                return false;}

            head=head->next;
            head1=head1->next;
           
        }
         return true;
        






        
    }
};