class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p = 0, n = 0;
        for(int i:nums){
            if(i == 0) return 0;
            else if(i<0) n++;
            else p++;
        }
        return n%2?-1:1;
    }
};