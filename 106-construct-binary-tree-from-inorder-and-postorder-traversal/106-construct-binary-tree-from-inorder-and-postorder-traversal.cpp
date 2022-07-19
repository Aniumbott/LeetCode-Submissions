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
    vector<int> inorder, postorder;
    
    TreeNode* helper(int i, int j, int ind){
        if(i > j) return NULL;
        TreeNode* root = new TreeNode(postorder[ind]);
        int index=i;
        while(postorder[ind] != inorder[index]) index++;
        root->right = helper(index+1, j, ind-1);
        root->left = helper(i, index-1, ind - (j-index) - 1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return helper(0, inorder.size() - 1, inorder.size() - 1);
    }
};