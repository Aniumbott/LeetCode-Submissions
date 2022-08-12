/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * We are transversing through tree using preorder so that we can check if root is one of asked nodes or not if it is then that has to be the LCA cause the other will bw in its subtree ans if ew able to find both nodes from one root then that root will be the LCA.
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)  return NULL;
        if(root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l && r) return root;
        return (l == NULL)? r: l;
    }
};