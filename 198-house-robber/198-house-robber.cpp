class Solution {
private:
    int helper(vector<int> nums, int i, vector<int> &dp){
        if(i==nums.size())return 0;
        if(dp[i] != -1) return dp[i];
        int mx=0;
        for(int j=i+2; j<nums.size(); j++) mx = max(mx, helper(nums, j, dp));
        return dp[i] = nums[i] + mx;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(100,-1);
        return max(helper(nums, 0, dp), helper(nums, 1, dp));
    }
};