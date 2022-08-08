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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        bool tgl = true;
        vector<vector<int>> ans = {{root->val}};
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int n=q.size();
            while(n--){
                TreeNode* tp = q.front();
                q.pop();
                if(tp->left){
                    q.push(tp->left);
                    v.push_back(tp->left->val);
                }
                if(tp->right){
                    q.push(tp->right);
                    v.push_back(tp->right->val);
                }
            }
            if(tgl) reverse(v.begin(), v.end());
            tgl = !tgl;
            if(v.size()) ans.push_back(v);
        }
        return ans;
    }
};