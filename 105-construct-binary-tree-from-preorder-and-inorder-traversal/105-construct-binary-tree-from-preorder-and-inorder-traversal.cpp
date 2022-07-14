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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& in, int l, int r){
        if(l > r) return NULL;
        int p = l;
        while(inorder[p] != preorder[in]) p++;
        in++;
        TreeNode* root = new TreeNode(inorder[p]);
        root->left =  helper(preorder, inorder, in, l, p-1);
        root->right =  helper(preorder, inorder, in, p+1, r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in=0;
        return helper(preorder, inorder, in, 0, inorder.size()-1);
    }
};