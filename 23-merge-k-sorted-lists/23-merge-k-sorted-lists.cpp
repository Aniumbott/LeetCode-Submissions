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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& a) {
        int k=a.size();
        
        if(k==0)return NULL;
        
        int i=0, last=k-1;
        int j=0;
        
        while(last!=0){
            i=0;
            j=last;
            while(i<j){
                a[i]=mergeTwoLists(a[i],a[j]);
                i+=1, j-=1;
            }
            last=j;
        }
        return a[0];
    }
};