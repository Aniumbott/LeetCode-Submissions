/*
Iterate till the node next to the middle one.
Then reverse the list from the current to the end,
Then merge these two list togeter.
 */
class Solution {
public:
    ListNode* reverseList(ListNode* l){
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(l){
            next = l->next;
            l->next = pre;
            pre = l;
            l = next;
        }
        return pre;
    }
    
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        int n=0;
        while(curr){
            n++;
            curr=curr->next;
        }
        if(n>1){
            int i=n/2;
            curr = head;
            while(i-->1)curr = curr->next;
            if(n%2)
                curr = curr->next;
            ListNode* rem = reverseList(curr->next);
            curr->next = NULL;
            curr = head;
            while(rem){
                ListNode* tmp = curr->next;
                curr->next = rem;
                rem = rem->next;
                curr->next->next = tmp;
                curr = curr->next->next;
            }
        }
    }
};