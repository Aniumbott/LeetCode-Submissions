class Solution {
private:
    vector<int> ans;
    int ind=0;
    void helper(int a, int n){
        if (a > n) return;
        ans[ind] = a;
        ind++;
        helper(a * 10, n);
        if (a % 10 != 9) helper(a+1, n);
    }
public:
    vector<int> lexicalOrder(int n) {
        ans.resize(n);
        helper(1, n);
        return ans;
    }
};