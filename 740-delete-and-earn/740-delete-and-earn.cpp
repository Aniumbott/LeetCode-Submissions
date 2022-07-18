class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        
        int dp[20005], ct[20005] = {0};
        
        for(auto i:nums) ct[i]++;
        
        dp[1] = ct[1];
        dp[2] = max(dp[1], ct[2]*2);
        
        for(int i=3; i<=mx; i++) dp[i] = max(dp[i-1], dp[i-2] + ct[i]*i);
        
        return dp[mx];
    }
};