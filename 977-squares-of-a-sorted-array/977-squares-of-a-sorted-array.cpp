class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 1) return {nums[0]*nums[0]};
        
        int m=0, mv=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(abs(nums[i]) < mv){
                mv = abs(nums[i]);
                m = i;
            }
        }
        
        int l=m-1, r=m+1;
        vector<int> ans = {nums[m]*nums[m]};
        while(l >=0 && r < nums.size()){
            if(abs(nums[l]) < nums[r]){
                    ans.push_back(nums[l] * nums[l]);
                    l--;
                }
                else if(abs(nums[l]) > nums[r]){
                    ans.push_back(nums[r]*nums[r]);
                    r++;
                }
                else {
                    ans.push_back(nums[l]*nums[l]);
                    ans.push_back(nums[r]*nums[r]);
                    l--;r++;
                }
        }
        while(r < nums.size()){
            ans.push_back(nums[r]*nums[r]);
            r++;
        }
        while(l >= 0){
            ans.push_back(nums[l]*nums[l]);
            l--;
        }
        return ans;
    }
};