class Solution {
public:
    bool isPalindrome(string s,int l,int r,bool t){
        while(l<r){
            if(s[l]!=s[r]){
                if(!t) return false;
                else return isPalindrome(s,l+1,r,false) || isPalindrome(s,l,r-1,false);
                t = false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        bool t = true;
        int l=0,r=s.size()-1;
        return isPalindrome(s,l,r,t);
    }
};