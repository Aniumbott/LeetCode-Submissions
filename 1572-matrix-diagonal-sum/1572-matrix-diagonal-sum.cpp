class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0, ans=0, n = mat.size();
        while(i < n){
            ans += mat[i][i] + mat[i][n-i-1];
            i++;
        }
        if(n%2) ans -= mat[n/2][n/2];
        return ans;
    }
};