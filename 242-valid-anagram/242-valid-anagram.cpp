class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int mp[26] = {0};
        for(auto c:s) mp[c-'a']++;
        for(auto c:t){
            if(mp[c-'a'] == 0) return false;
            mp[c-'a']--;
        }
        return true;
    }
};