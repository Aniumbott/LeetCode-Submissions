class Solution {
private:
    int M, N, Mx, mod = 1000000007;
    
    int helper(int x, int y, int m, vector<vector<vector<int>>>& dp){
        if(x < 0 || y < 0 || x >= M || y >= N) return 1;
        if(m == Mx) return 0;
        if(dp[m][x][y] != -1) return dp[m][x][y] % mod;
        int t=0;
        t = (t + helper(x-1, y, m+1, dp))% mod;
        t = (t + helper(x+1, y, m+1, dp))% mod;
        t = (t + helper(x, y-1, m+1, dp))% mod;
        t = (t + helper(x, y+1, m+1, dp))% mod;
        dp[m][x][y] = t;
        return dp[m][x][y]%mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        this->M = m;
        this->N = n;
        this->Mx = maxMove;
        dp[maxMove][m][n] = helper(startRow, startColumn, 0, dp);
        return dp[maxMove][m][n];
    }
};