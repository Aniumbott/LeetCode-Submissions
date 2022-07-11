class Solution {
public:

    int maxProduct(vector<int>& nums) {
        
        int ans = nums[0] ,mxe = nums[0] , mne = nums[0];
        for(int i =1; i< nums.size(); i++){
            int temp = mxe;
            mxe = max({nums[i], nums[i]*mxe, nums[i]*mne});
            mne = min({nums[i], nums[i]*temp, nums[i]*mne});
            ans = max(ans, mxe);
        } 
        return ans;
    }
};