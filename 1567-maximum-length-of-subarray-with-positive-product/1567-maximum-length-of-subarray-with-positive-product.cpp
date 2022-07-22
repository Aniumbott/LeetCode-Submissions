class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int i=0, nn=0, s=-1, fn=-2, ans = 0;
        while(i<nums.size()){
            if (nums[i] == 0){ nn = 0; s = i; fn = -2; } 
            else 
            {
                if (nums[i] < 0) nn++; 
                if (nn == 1 && fn == -2) fn = i;  
                if (nn % 2 == 0) ans = max(ans, i - s); 
                else ans = max(ans, i - fn); 
            }
            i++;
        }
        return ans;
    }
};