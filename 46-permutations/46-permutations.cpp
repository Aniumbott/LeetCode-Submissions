class Solution {
private:
    vector<vector<int> > ans;
    vector<int> nums;
    
    void helper(int i) {
        
        if (i == nums.size()) ans.push_back(nums);
        
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            helper(i + 1);
            swap(nums[i], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        helper(0);
        return ans;
    }
};