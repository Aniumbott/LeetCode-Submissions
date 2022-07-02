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
    bool helper(TreeNode* root, int ans, int limit){
        if(!root->left && !root->right){
            if(ans+root->val < limit)
                return false;
            return true;
        }
        
        bool left = (root->left)?helper(root->left, ans+root->val, limit):false;
        bool right = (root->right)?helper(root->right, ans+root->val, limit):false;
        
        if(left && right) return true;
        if(!right && !left) return false;
        if(!right) root->right = NULL;
        if(!left) root->left = NULL;
        return true;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(helper(root, 0, limit))
            return root;
        return NULL;
    }
};