class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i+1 < nums.size()){
            for(int k=0; k<nums[i]; k++) ans.push_back(nums[i+1]);
            i+=2;
        }
        return ans;
    }
};