class Solution {
private:
    bool helper(TreeNode*root, int k, vector<vector<bool>> &dp){
        if(!root) return false;
        
        int a = k - root->val, i = (a >= 0);
        
        if(abs(a) < 10000 && dp[i][abs(a)] == true) return true;
        
        i = (root->val >= 0);
        
        dp[i][abs(root->val)] = true;
        
        return helper(root->left, k, dp) || helper(root->right, k, dp);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<vector<bool>> dp( 2 , vector<bool> (10001, 0));
        return helper(root, k, dp);
    }
};