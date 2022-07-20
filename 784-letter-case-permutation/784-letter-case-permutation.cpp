class Solution {
private: 
    vector<string> ans;
    bool isChar(char c){ return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')); }
    
    char toggleCase(char c){
        if(c >= 'a' && c <= 'z') return c - 'a' + 'A';
        else return c - 'A' + 'a';
    }
    
    void helper(int i, string s, int k){
        if(i == s.size()) return;
        
        for(int j=i; j<s.size(); j++){
            if(isChar(s[j])){
                s[j] = toggleCase(s[j]);
                ans.push_back(s);
                helper(j+1, s, k-1);
                s[j] = toggleCase(s[j]);
            }
        }
    }
        
public:
    vector<string> letterCasePermutation(string s) {
        ans.push_back(s);
        helper(0, s, s.size());
        return ans;  
    }
};  