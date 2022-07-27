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
private:
    bool mp[10001];
    
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        if(!head) return 0;
        
        int ans = 0;
        
        for(auto i:nums) mp[i] = true;
        
        while(head != NULL){
            
            if(mp[head->val]){
                ans++;
                while(head != NULL && mp[head->val]) head = head->next;    
            }
            
            else head = head->next;
        }
        
        return ans;
    }
};