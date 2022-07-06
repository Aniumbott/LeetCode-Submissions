class Solution {
public:
    string longestPalindrome(string s) {
        
        int st=0, en=0;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            
            int l, r;
            
            for(l = i, r = i+1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if((r-l+1) > (en-st+1)) {
                    st=l; 
                    en = r;
                }
            }
            
            for(l = i-1, r = i+1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if((r-l+1) > (en-st+1)) {
                    st=l; 
                    en = r;
                }
            }
            
        }
        
        return s.substr(st, en-st+1);
    }
};