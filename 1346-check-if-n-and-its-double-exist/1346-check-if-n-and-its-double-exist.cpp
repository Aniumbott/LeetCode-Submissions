class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto i:arr) mp[i]++;
        for(auto i:arr){ if((i!=0 && mp[2*i]) || (i==0 && mp[0] > 1)) return true; }
        return false;
    }
};