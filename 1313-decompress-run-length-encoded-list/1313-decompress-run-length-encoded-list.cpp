class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int i=0, j=1;
        while(j < nums.size()){
            for(int k=0; k<nums[i]; k++) ans.push_back(nums[j]);
            i+=2;
            j+=2;
        }
        return ans;
    }
};