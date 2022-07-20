class Solution {
private:
    vector<vector<int> > ans;
    
    void helper(vector<int> nums, int i) {
        if (i == nums.size()){ ans.push_back(nums); return; }
        
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            helper(nums, i + 1);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }
};