class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=min(word1.size(), word2.size()), i;
        string s = "";
        
        for(i=0; i<n; i++){ s = s + word1[i] + word2[i]; }
        
        while(i < word1.size()){ s += word1[i]; i++; }
        
        while(i < word2.size()){ s += word2[i]; i++; }
        
        return s;
    }
};