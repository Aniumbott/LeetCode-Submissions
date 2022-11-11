class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ct=0, i=0, n=nums.size();
        while(i<n) {
            nums[ct] = nums[i];
            while(i<n && nums[ct]==nums[i]) i++;
            ct++;
        }
        return ct;
    }
};