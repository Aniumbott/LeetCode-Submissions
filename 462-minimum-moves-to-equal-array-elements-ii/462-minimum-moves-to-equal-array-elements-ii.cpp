class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m, ans=0;
        if(nums.size()%2) m=nums[nums.size()/2];
        else m= (nums[nums.size()/2] + nums[(nums.size()/2)-1])/2;
        for(auto i:nums) ans += abs(i-m);
        return ans;
    }
};