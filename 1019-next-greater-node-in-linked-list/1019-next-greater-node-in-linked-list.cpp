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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
  
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverseList(head);
        
        vector<int> ans;
        stack<int> st;
        
        while(head != NULL) {
            while(!st.empty() && st.top() <= head->val) st.pop();
            if(!st.empty()) ans.push_back(st.top());
            else ans.push_back(0);
            st.push(head->val);
            head = head->next;
        }
        
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};