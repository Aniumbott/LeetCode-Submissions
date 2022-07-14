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
    TreeNode* dfs(vector<int> &preorder, unordered_map<int,int>& mp, int& in, int left, int right) {
        if (left > right) return nullptr;
        TreeNode *root = new TreeNode(preorder[in++]);
        int mid = mp[root->val];
        root->left = dfs(preorder, mp, in, left, mid - 1);
        root->right = dfs(preorder, mp, in, mid + 1, right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in=0;
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        return dfs(preorder, mp, in, 0, inorder.size()-1);
    }
};