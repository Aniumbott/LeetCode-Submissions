class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = ((nums.size())*(nums.size()+1))/2;
        for(auto i:nums) n-=i;
        return n;
    }
};