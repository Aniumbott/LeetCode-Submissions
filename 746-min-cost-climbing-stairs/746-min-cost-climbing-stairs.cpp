class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        dp[0] = 0;
        dp[1] = cost[0];
        for(int i=1; i<cost.size(); i++)
            dp[i+1] = cost[i] + min(dp[i],dp[i-1]);
        
        return min(dp[cost.size()-1],dp[cost.size()]);
    }
};