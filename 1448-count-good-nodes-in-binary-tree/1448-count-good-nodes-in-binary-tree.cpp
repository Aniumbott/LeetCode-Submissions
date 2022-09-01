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
    int helper(TreeNode*root, int mx){
        if(!root) return 0;
        int c = root->val >= mx ? 1 : 0;
        mx = max(mx, root->val);
        return c + helper(root->left, mx) + helper(root->right, mx);
    }
public:
    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        return helper(root, mx);
    }
};