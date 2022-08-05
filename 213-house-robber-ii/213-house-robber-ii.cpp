class Solution {
private:
    int helper(vector<int>& nums, int j, int n) {
        int pre = 0, cur = 0;    
        for (int i = j; i <= n; i++)
        {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
};