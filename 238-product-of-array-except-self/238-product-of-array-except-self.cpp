class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int ans = 1;
        int ct=0;
        
        for(auto i:nums){
            if(i != 0) ans *= i;
            else ct++;
        }
        
        vector<int> v;
        
        for(auto i:nums){
            if(ct > 1 || (ct == 1 && i != 0)) v.push_back(0); 
            else if(i == 0) v.push_back(ans);
            else v.push_back(ans/i);
        }

        return v;
    }
};