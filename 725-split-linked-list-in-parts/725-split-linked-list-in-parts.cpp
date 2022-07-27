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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {   
        int n=0;
        ListNode *cur = head;
        vector<ListNode*> ans;
        
        while(cur != NULL){ n++; cur = cur->next; }
        
        int m=n/k; 
        int e=n%k;  
        int i=0;
        cur=head;
        while(cur)
        {
            ans.push_back(cur);
            
            int currLen=1;
            while(currLen<m)
            {
                cur=cur->next;
                currLen++;
            }
            
            if(e>0 && n>k)
            {
                cur=cur->next;
                e--;
            }
            
            ListNode* x=cur->next;
            cur->next=NULL;
            cur=x;
        }
        
        while(n<k) { ans.push_back(NULL); n++; }
        
        return ans;
        
    }
};