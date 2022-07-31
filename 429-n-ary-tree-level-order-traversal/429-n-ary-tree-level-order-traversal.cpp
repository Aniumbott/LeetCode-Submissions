/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        
        if(root==NULL)return v;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            vector<int> ans;
        
            while(s-->0){
                Node *temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                for(auto &t:temp->children){
                    if(t!=NULL) q.push(t);
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};