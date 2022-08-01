/*
There are multiple possible solutions one with comparission with a rebverse linked list and one with the stack which is shown but another one is two pointer method which is still remaining, will see it latter 
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n=0;
        stack<ListNode*> st;
        ListNode* test=head;
        while(test!=NULL){
            n++;
            test=test->next;
        }
        int ns = n/2;
        test = head;
        while(ns-->0){
            st.push(test);
            test = test->next;
        }
        if(n%2) test = test->next;
        ns = n/2;
        while(ns-->0){
            if(st.top()->val != test->val) return false;
            st.pop();
            test = test->next;
        }
        return true;
    }
};