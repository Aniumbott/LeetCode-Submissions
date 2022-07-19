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
    vector<vector<int>> ans;
    
    void helper(TreeNode* node, int sum, vector<int>& path) {
        if (!node) return;
        
        path.push_back(node -> val);
        
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            ans.push_back(path);
        
        helper(node -> left, sum - node -> val, path);
        helper(node -> right, sum - node -> val, path);
        
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        helper(root, sum, path);
        return ans;  
    }
};