class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int> mp, mp1, mp2, mp3;
        vector<int> ans;
        
        for(auto i : nums1) mp1[i]++;
        for(auto i : nums2) mp2[i]++;
        for(auto i : nums3) mp3[i]++;
        
        for(auto i : mp1)
            if(mp2.find(i.first) != mp2.end()) mp[i.first]++;
        
        for(auto i : mp2)
            if(mp3.find(i.first) != mp3.end()) mp[i.first]++;
        
        for(auto i : mp1)
            if(mp3.find(i.first) != mp3.end()) mp[i.first]++;
        
        for(auto i : mp)
            if(i.second > 0) ans.push_back(i.first);
        
        return ans;
    }
};