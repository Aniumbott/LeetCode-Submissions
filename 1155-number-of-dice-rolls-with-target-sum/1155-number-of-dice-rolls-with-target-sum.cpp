class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int m=1000000007;
        vector<vector<int> > dp(n+1, vector<int>(target+1, 0));
        dp[0][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                for(int f=1; f<=k; f++){
                    if(f<=j)
                        dp[i][j]=((dp[i][j]%m)+(dp[i-1][j-f]%m))%m;
                }
            }
        }
        return dp[n][target];
    }
};