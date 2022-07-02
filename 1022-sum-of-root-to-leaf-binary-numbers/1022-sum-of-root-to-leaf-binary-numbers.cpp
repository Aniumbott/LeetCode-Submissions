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
    void helper(TreeNode*root, int &ans, string s){
        if(!root) return;
        
        if(root->left == NULL && root->right == NULL)
            ans += stoi(s+to_string(root->val), 0, 2);
        
        helper(root->left, ans, s+to_string(root->val));
        helper(root->right, ans, s+to_string(root->val));
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        helper(root, ans, "");
        return ans;
    }
};