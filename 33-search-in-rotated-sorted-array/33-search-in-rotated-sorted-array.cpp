class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        while(i < nums.size() && nums[i] != target) i++;
        return (i == nums.size())?-1:i;
    }
};