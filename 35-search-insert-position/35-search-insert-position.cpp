class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int val=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target){
                val+=1;
            }
        }
        return val;
    }
};