class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> rt;
        int ans = 0;
        for(auto i:nums)
            if(i%2 == 0) ans += i;
        for(auto a:queries){
            if(nums[a[1]]%2 == 0)
                ans -= nums[a[1]];
            
            nums[a[1]] += a[0];
            
            if(nums[a[1]]%2 == 0) 
                ans += nums[a[1]];
            
            rt.push_back(ans);
        }
        return rt;
    }
};