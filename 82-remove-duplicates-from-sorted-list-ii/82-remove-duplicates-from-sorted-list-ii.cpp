/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 Comparing the next and the next next node while they are same and modifying the list accordingly.
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* curr = new ListNode(0);
        curr->next = head;
        head = curr;
        while(curr->next && curr->next->next){
            if(curr->next->val == curr->next->next->val){
                int x = curr->next->val;
                while(curr->next && curr->next->val == x) curr->next = curr->next->next;    
            }
            else curr = curr->next;
        }
        return head->next;
    }
};