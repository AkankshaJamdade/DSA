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
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        //save all in a list then sort
        ListNode* temp=head;
        vector<int>values;
        while(temp){
            values.push_back(temp->val);
            temp=temp->next;
        }
        sort(values.begin() , values.end());
        //fill the linked list with sorted no
        ListNode* temp1=head;
        for(int i=0; i<values.size(); i++){
            temp1->val=values[i];
            temp1=temp1->next;
        }
        return head;
    }
};