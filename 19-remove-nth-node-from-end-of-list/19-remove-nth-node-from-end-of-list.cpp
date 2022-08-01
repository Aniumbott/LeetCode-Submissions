/*
Calculate the lenngth of the list
Then iterate till the reaches the just previous node of the nth one.
Then just change the connections.
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int l=0;
        while(curr){
            l++;
            curr = curr->next;
        }
        if(l == n)
            return head->next;
        int i=l-n;
        curr = head;
        while(i-->1) curr=curr->next;
        curr->next = curr->next->next;
        return head;
    }
};