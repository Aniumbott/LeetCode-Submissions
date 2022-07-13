class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p = 1;
        for(int i:nums){
            if(i == 0) return 0;
            else if(i < 0) p*=-1;
        }
        return p;
    }
};