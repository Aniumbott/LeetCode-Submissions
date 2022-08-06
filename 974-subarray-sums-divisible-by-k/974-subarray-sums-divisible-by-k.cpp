class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;                   
        int mapp[30001] = {0};
        mapp[0]++;
        int presum = 0;
        int rem = 0;		
        
        for(int i=0; i<nums.size(); i++)
        {
            presum += nums[i];
            rem = presum % k;
            
            if(rem < 0) rem += k;
            
            if(mapp[rem]){ ans += mapp[rem]; mapp[rem]++; }
            else mapp[rem]++;
        }
        return ans;
    }
};