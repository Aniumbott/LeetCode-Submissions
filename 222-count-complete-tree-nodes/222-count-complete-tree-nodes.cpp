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
    
    int heightl(TreeNode* root){
        int ans=0;
        while(root){
            root = root->left;
            ans++;
        }
        return ans;
    }
    
    int heightr(TreeNode* root){
        int ans=0;
        while(root){
            root = root->right;
            ans++;
        }
        return ans;
    }
    
    
    int helper(TreeNode*root){
        int l=heightl(root), r=heightr(root);
        if(l==r) return (pow(2, l)-1);
        else return 1 + helper(root->left) + helper(root->right);  
    }
        
public:
    int countNodes(TreeNode* root) {
        return helper(root);
    }
};