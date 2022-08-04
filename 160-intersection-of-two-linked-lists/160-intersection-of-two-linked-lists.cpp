/*
There is two different approches are possible one with hash table with space complexity m+n and the othe reffective solution is with space complexity 1 which is shown and in both the cases the time complexity is O(n).
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0, n2=0;
        ListNode* l1=headA;
        ListNode* l2=headB;
        while(l1){
            n1++;
            l1=l1->next;
        }
        while(l2){
            n2++;
            l2=l2->next;
        }
        if(n1==0 || n2==0)return NULL;
        l1 = headA;
        l2 = headB;
        if(n1>n2){
            swap(l1, l2);
        }
        int it = max(n1,n2) - min(n1,n2);
        while(it-->0){
            l2=l2->next;
        }
        it = min(n1,n2);
        
        while(it-->0){
            if(l2 == l1) return l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        return NULL;
    }
};