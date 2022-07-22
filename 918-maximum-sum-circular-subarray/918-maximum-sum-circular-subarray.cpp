class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx=INT_MIN,mn=INT_MAX,s1=0,s2=0,ts=0;   
        for(auto i:nums)
        {
            ts+=i; s1+=i; s2+=i;
            mx=max(mx,s1);
            if(s1<0) s1=0;
            mn=min(s2,mn);
            if(s2>0) s2=0;
        }
        if(ts==mn) return mx;
        else return max(mx,ts-mn);
    }
};