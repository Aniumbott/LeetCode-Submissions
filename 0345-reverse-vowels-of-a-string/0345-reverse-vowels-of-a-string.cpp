class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        else return false;
    }
    
    string reverseVowels(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            while(!isvowel(s[l]) && l<s.size()) l++;
            while(!isvowel(s[r]) && r>0) r--;
            if(l<r) swap(s[l++], s[r--]);
        }
        return s;
    }
};