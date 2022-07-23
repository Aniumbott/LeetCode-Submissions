/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = max(p->val, q->val), b = min(p->val, q->val);
        if(a == root->val || b == root->val || (a > root->val && b < root->val)){
            return root;
        }
        return (a < root->val)?lowestCommonAncestor(root->left, p, q):lowestCommonAncestor(root->right, p , q);
    }
};