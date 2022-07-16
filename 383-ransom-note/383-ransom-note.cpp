class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mp[26] = {0};
        for(auto c:magazine) mp[c-'a']++;
        for(auto c:ransomNote){
            if(mp[c-'a'] == 0) return false;
            mp[c-'a']--;
        }
        return true;
    }
};