class Solution {
private:
    bool helper(int n, int k, vector<int> nums){
        vector<bool> prev(k+1, false), cur(k+1, false);
        
        prev[0] = cur[0] = true;
        
        if(nums[0] <= k) prev[nums[0]] = true;
        
        for(int i=1; i < n; i++){
            for(int t=1; t<=k; t++){
                bool ntk = prev[t];
                bool tk = false;
                if(nums[i] <= t) tk = prev[t-nums[i]];
                cur[t] = tk | ntk;
            }
            prev = cur;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(auto i:nums) s+=i;
        if(s%2) return false;
        return helper(nums.size(), s/2, nums);
    }
};