class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int s = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            s += nums[i];
            s %= k;
            if(s == 0 && i) return true;
            if(mp.find(s) != mp.end()){ if(i - mp[s] > 1) return true; }
            else mp[s] = i;
        }
        return false;
    }
};