class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = ((nums.size())*(nums.size()+1))/2, s=0;
        for(auto i:nums) s+=i;
        return n-s;
    }
};