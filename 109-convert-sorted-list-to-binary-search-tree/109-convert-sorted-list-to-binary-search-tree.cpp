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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    ListNode* head;
    
    TreeNode* helper(int l, int r){
        if(l > r) return NULL;
        int m = l+(r-l)/2;
        TreeNode*root = new TreeNode(0);
        root->left = helper(l, m-1);
        root->val = head->val;
        head = head->next;
        root->right = helper(m+1, r);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        this->head=head;
        int n=0;
        while(head){ n++; head=head->next; }
        return helper(0, n-1);
    }
};