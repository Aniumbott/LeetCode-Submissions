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
public:
    /*
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l, r;
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        return max(l, r) + 1;
    }
    */
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int max = 1;
        queue<TreeNode*> q;
        q.push(root);
        root -> val = max;
        while(!q.empty()){
            TreeNode*tp = q.front();
            q.pop();
            if(tp->left){
                q.push(tp->left);
                tp->left->val = tp->val + 1;
                max = tp->val + 1;
            }
            if(tp->right){
                q.push(tp->right);
                tp->right->val = tp->val + 1;
                max = tp->val + 1;
            }
        }
        return max;
    }
};