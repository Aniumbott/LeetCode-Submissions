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
    int maxd = 0;
    int findDiameter(TreeNode* root){
        if(root == NULL) return 0;
        int ld = findDiameter(root->left);
        int rd = findDiameter(root->right);
        maxd = max(maxd, ld+rd+1);
        return max(ld+1,rd+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findDiameter(root);
        return maxd-1;
    }
};