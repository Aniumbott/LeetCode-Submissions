class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), m = (n%2)?nums[n/2]:(nums[n/2]+nums[n/2-1])/2; 
        int ans=0;
        for(auto i:nums) ans += abs(i-m);
        return ans;
    }
};