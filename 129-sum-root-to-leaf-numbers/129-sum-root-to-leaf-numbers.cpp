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
    void helper(TreeNode* root, int& ans, int sum){
        if(!root) return;
        sum += root->val;
        if((!root->right) && (!root->left)){ ans += sum; return; }
        helper(root->left, ans, sum*10);
        helper(root->right, ans, sum*10);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, ans, 0);
        return ans;
    }
};