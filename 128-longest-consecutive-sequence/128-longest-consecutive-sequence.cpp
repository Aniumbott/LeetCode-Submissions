class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        int l = 1;
        int ans = 1;
        
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i+1] == nums[i])
                continue;
            
            else if(nums[i+1] == nums[i] + 1){
                l++;
            }
            else
                l = 1;
            
            if(l>ans) 
                ans = l;
            
        }
        
        return ans;
    }
};