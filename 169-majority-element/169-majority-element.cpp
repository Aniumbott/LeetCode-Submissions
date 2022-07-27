class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=0, n=0;
        for(int i:nums){
            if(ct == 0){
                n = i;
            }
            if(i == n){
                ct++;
            }
            else{
                ct--;    
            }
        }
        return n;
    }
};