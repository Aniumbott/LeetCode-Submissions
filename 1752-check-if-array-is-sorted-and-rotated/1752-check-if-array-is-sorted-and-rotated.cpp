class Solution {
public:
    bool check(vector<int>& nums) {
        int s=0, i=1, m = INT_MAX;
        while(i<nums.size()){
            if(nums[i] < nums[i-1]) s=i;
            i++;
        }
        // cout << s << endl;
        for(int i = s+1; i%nums.size() != s; i++){
            if(nums[(i-1)%nums.size()] > nums[i%nums.size()]){
                // cout << i << endl;
                return false;
            }
        }
        return true;
    }
};