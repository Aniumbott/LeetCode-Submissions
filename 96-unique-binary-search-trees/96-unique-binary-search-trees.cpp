class Solution {
public:
    int helper(int dp[20], int n){
        if(n < 2) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans += helper(dp, i - 1) * helper(dp, n - i);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        int dp[21];
        memset(dp, -1, sizeof dp);
        int result = helper(dp, n);
        return result; 
    }
};