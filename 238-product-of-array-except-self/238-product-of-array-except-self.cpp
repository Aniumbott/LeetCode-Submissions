class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long ans = 1;
        int ct=0;
        
        for(auto i:nums){
            if(i != 0) ans *= (long long)i;
            else ct++;
        }
        
        vector<int> v(nums.size(),0);
        
        for(int i=0; i<nums.size(); i++){
            if(ct > 1 || (ct == 1 && nums[i] != 0)) v[i] = 0; 
            else if(nums[i] == 0) v[i] = ans;
            else v[i] = ans/nums[i];
        }

        return v;
    }
};