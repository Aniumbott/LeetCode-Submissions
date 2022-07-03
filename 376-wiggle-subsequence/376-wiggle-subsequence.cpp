class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int a=1, b=1;
        for(int i=1; i<nums.size(); i++){
                 if(nums[i]>nums[i-1]) a=b+1;
            else if(nums[i]<nums[i-1]) b=a+1;
        }
        return min((int)nums.size(), max(a, b));
    }
};