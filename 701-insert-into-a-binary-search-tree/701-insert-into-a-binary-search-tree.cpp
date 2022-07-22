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
    void helper(TreeNode* root, int val){
        if(root->val > val){
            if(root->left == NULL){
                TreeNode *node = new TreeNode(val);
                root->left = node;
            }
            else helper(root->left, val);
        }
        else{
            if(root->right == NULL){
                TreeNode *node = new TreeNode(val);
                root->right = node;
            }
            else helper(root->right, val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){ root = new TreeNode(val); return root; }
        helper(root, val);
        return root;
    }
};