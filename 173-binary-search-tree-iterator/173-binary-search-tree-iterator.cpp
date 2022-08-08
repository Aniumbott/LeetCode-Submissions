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
class BSTIterator {
public:
    stack<int> s;
    BSTIterator(TreeNode* root) {
       mkInorder(root);
    }
    
    void mkInorder(TreeNode* root){
        if(!root) return;
        mkInorder(root->right);
        s.push(root->val);
        mkInorder(root->left);
    }
    
    int next() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    bool hasNext() {
        if(s.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */