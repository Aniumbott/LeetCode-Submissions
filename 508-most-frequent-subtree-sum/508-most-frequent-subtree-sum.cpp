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
    unordered_map<int, int> mp;
    int ms = 0;
    
    int helper(TreeNode *root){
        if(!root) return 0;
        int a = root->val + helper(root->left) + helper(root->right);
        mp[a]++;
        ms = max(ms, mp[a]);
        return a;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int> ans;
        for(auto i:mp) if(i.second == ms) ans.push_back(i.first);
        return ans;
    }
};