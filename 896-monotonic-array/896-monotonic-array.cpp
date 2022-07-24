class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i;
        for(i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]) break;
        }
        if(i == nums.size()) return true;
        i=1;
        for(i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]) break;
        }
        if(i == nums.size()) return true;
        return false;
    }
};