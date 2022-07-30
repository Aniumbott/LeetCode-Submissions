class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        
        vector<int> ans;
        int mp[26] = {0};
        for(auto c:p) mp[c-'a']++;
        for(int i=0; i<= s.size()-p.size(); i++){
            
            int tmp[26] = {0};
            int j=i;
            
            while(j-i < p.size()){ tmp[s[j]-'a']++; j++; }
            
            for(j=0; j<26; j++) if(mp[j] != tmp[j]) break;
            
            if(j == 26) ans.push_back(i);
        }
        return ans;
    }
};