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
    int t=0;
    vector<int> v;
    int mod = 1e9 + 7;
    void helper(TreeNode* root, int k){
        if(!root) return;
        v.push_back(root->val);
        helper(root->left, k);
        helper(root->right, k);
        int f=0;
        for(int i= v.size()-1; i>=0; i--){
            f = (f + v[i]%mod)%mod;
            if(f == k) t++;
        }
        v.pop_back();
    }
    
    int pathSum(TreeNode* root, int k) {
        helper(root, k);
        return t;
    }
};