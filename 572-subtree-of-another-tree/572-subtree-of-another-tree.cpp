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
    bool isSame(TreeNode* root, TreeNode* subroot){
        if(!root || !subroot) return root == subroot;
        if(root->val != subroot->val) return false;
        return isSame(root->left, subroot->left) && isSame(root->right, subroot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root || !subroot) return root == subroot;
        if(isSame(root, subroot)) return true;
        else return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
};