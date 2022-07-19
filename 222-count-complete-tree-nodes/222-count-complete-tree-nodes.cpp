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
    struct pir{ int first = -1, second = - 1; };

    unordered_map<TreeNode*, pir> dp;
    
    int heightl(TreeNode*root){
        if(!root) return 0;
        if(dp[root].first != -1) return dp[root].first;
        return dp[root].first = 1 + heightl(root->left);
    }
    
    int heightr(TreeNode*root){
        if(!root) return 0;
        if(dp[root].second != -1) return dp[root].second;
        return dp[root].second = 1 + heightr(root->right);
    }
    
    
    int helper(TreeNode*root){
        int l=heightl(root), r=heightr(root);
        if(l==r) return (pow(2, l)-1);
        else return 1 + helper(root->left) + helper(root->right);  
    }
        
public:
    int countNodes(TreeNode* root) {
        return helper(root);
    }
};