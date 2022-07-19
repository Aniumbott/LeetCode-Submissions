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
    int ans=INT_MIN;
    
    int helper(TreeNode* root){
        if(!root) return 0;
        ans = max(ans, root->val);
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return ans;
    }
};