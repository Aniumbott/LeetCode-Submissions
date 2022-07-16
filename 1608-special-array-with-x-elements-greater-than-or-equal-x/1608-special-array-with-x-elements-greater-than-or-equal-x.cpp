class Solution {
public:
    int specialArray(vector<int>& nums) {
        int mp[102];
        memset(mp, 0, sizeof mp);
        for(auto i:nums) mp[(i>=100)?100:i]++;
        for(int i=100; i>0; i--){
            mp[i] += mp[i+1];
            if(mp[i] == i) return i;
        }
        return -1;
    }
};