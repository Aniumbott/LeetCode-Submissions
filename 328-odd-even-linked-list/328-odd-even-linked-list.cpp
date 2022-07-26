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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *h1 = head, *h2 = head->next, *p = h2;
        while(p && p->next)
        {
            h1->next = h1->next->next;
            p->next = p->next->next;
            h1 = h1->next;
            p = p->next;
        }
        h1->next = h2;
        return head;
    }
};