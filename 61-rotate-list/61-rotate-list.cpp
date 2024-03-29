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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
    
        int n = 1;
        ListNode *cur = head;
        
        while(cur->next != NULL){ n++; cur = cur->next; }
        
        cur->next = head;
        k %= n;
        
        while(--n >= k) cur = cur->next;
        
        ListNode *ans = cur->next;
        cur->next = NULL;
        
        return ans;
    }
};