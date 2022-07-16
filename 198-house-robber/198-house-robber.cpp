class Solution {
private:
    int helper(vector<int> nums, int i, vector<int> &dp){
        if(i>=nums.size())return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i] + helper(nums, i+2, dp), helper(nums, i+1, dp));
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(100,-1);
        return helper(nums, 0, dp);
    }
};