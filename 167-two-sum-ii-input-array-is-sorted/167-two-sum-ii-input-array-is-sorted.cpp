class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); i++)
        {
            int key = target - nums[i];
            if(!hash.count(key))
                hash[nums[i]] = i;
            else
            {
                ans = {hash[key]+1, i+1};
                break;
            }
        }
        return ans;
        
    }
};