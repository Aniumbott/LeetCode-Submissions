class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        vector<int> ans;
        for(int i:nums1) mp1[i]++;
        for(int i:nums2) mp2[i]++;
        for(auto i:mp1){
            int n= min(i.second, mp2[i.first]);
            while(n--) ans.push_back(i.first);
        }
        return ans;
    }
};