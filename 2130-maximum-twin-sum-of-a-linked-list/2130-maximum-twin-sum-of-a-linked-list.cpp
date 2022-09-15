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
    ListNode* reverseList(ListNode *head){
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
public:
    int pairSum(ListNode* head) {
        if(!head) return 0;
        ListNode* cur = head, *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        int ans = 0;
        while(slow){
            ans = max(ans, cur->val + slow->val);
            cur = cur->next;
            slow = slow->next;
        }
        return ans;
    }
};