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
    int sum = 0;
    bool isLeaf(TreeNode* root){
        if(!root) return false;
        if(!root->right && !root->left) return true;
        return false;
    }
    
    void helper(TreeNode*root){
        if(!root) return;
        if(isLeaf(root->left)){
            sum += root->left->val;
        }
        helper(root->left);
        helper(root->right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return sum;
    }
};