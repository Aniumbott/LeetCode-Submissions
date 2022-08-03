/*
Do a simple summition by taking carry along
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode();
        ListNode* temp = head;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int v1, v2;
            if(l1 != NULL){
                v1 = l1->val;
                l1 = l1->next;
            }
            else   v1 = 0;
            
            if(l2 != NULL){
                v2 = l2->val;
                l2 = l2->next;
            }
            else   v2 = 0;
            
            int sum = carry + v1 + v2;
            carry = sum/10;
            head->next = new ListNode(sum % 10);
            head = head->next;
            if(carry > 0){
                head->next = new ListNode(carry);
            }
        }
        return temp->next;
    }
};