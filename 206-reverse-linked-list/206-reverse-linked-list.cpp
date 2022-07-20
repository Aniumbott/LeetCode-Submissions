/*
tWe ake two saparate node to tack of the pre and next node of the head so we can reverse it
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* nxt = NULL;
        ListNode* pre = NULL;
        while(head){
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        head = pre;
        return head;
    }
};