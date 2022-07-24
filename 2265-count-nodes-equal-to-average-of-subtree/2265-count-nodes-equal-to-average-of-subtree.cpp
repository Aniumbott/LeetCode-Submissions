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
    int ct=0;
    pair<int, int> helper(TreeNode *root){
        if(root==NULL) return {0,0};
        
        auto left=helper(root->left);
        
        auto right=helper(root->right);
        
        int sum = (left.first + right.first + root->val);
        int n = (left.second + right.second + 1);        
        ct += ((sum/n) == root->val);
        
        return { sum , n };
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ct;
    }
};