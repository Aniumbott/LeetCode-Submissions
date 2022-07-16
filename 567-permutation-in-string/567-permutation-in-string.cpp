class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int mp[26] = {0};
        for(auto c:s1) mp[c-'a']++;
        for(int i=0; i<s2.length(); i++){
            if(mp[s2[i]-'a']){
                int p[26] = {0}, j;
                for(j=0; j<s1.length() && i+j < s2.length(); j++){
                    p[s2[i+j]-'a']++;
                    if(mp[s2[i+j]-'a'] < p[s2[i+j]-'a']) break;
                }
                if(j == s1.length()) return true;
                
                // i+=(j-1);
                // cout << i << " ";
            }
        }
        return false;
    }
};