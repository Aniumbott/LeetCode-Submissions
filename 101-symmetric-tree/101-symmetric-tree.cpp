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
    bool issym(TreeNode* l, TreeNode* r){
        if(!l || !r) return l == r;
        bool rt = l->val == r->val;
        return rt && issym(l->left, r->right) && issym(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return issym(root->left, root->right);
    }
};