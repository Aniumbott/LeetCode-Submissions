class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        int ct[26] = {0};
        for(auto c:s)
            ct[c-'a']++;
        for(auto c:order)
            while(ct[c-'a']--) ans += c;
        for(int i=0; i<26; i++)
            if(ct[i] > 0)
                while(ct[i]--)
                    ans += (char)('a'+i);
        return ans;
    }
};