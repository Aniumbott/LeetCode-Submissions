class Solution {
private:
    vector<vector<int> > ans;
    vector<int> v;
    
    void helper(int i, int n, int k) {
        while (i <= n) {
            v[v.size() - k] = i++;
            
            if (k > 1) helper(i, n, k - 1);
            
            else ans.push_back(v);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        v.resize(k);
        helper(1, n, k);
        return ans;
    }
};