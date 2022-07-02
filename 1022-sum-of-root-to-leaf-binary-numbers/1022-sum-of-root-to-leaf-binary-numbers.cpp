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
    void helper(TreeNode*root, int &ans, int p){
        if(!root) return;
        
        p = (p<<1)+root->val;
        if(root->left == NULL && root->right == NULL)
            ans += p;
        
        helper(root->left, ans, p);
        helper(root->right, ans, p);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        helper(root, ans, 0);
        return ans;
    }
};