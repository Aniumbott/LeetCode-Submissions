/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 In simple words we are building a saparate list of nodes having value less than x and then just connect the end of it to the old list's modified head.
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = new ListNode(0);
        ListNode* temp = new ListNode(0);
        ListNode* tcurr = temp;
        curr->next = head;
        head = curr;
        while(curr){
            if(curr->next && curr->next->val < x){
                tcurr->next = curr->next;
                tcurr =  tcurr->next;
                curr->next = curr->next->next;
            }
            else curr = curr->next;
        }
        tcurr->next = head->next;
        return temp->next;
    }
};