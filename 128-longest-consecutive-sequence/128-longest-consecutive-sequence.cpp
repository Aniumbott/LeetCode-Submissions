class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(nums[i] - 1)!=s.end())
                continue;
            
            else
            {
                int ct = 0, x = nums[i];
                
                while(s.find(x) != s.end())
                {
                    ct++;
                    x++;
                }
                
                ans = max(ans,ct);
            }
        }
        
        return ans;
    }
};