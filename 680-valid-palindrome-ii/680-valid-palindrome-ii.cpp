class Solution {
public:
    bool afterDeleting( string s ,int i,int j){
         int ii=i;
         int jj =j;
        while(ii<jj){
           if(s[ii] != s[jj]){
               return false;
           }else{
               ii++;
               jj--;
           }
            
        }
        return true;
    }
    
    bool checkpalindrome(string s){
        int i=0;
        int e =s.length()-1;
        
        while(i<e){
            if(s[i] != s[e]){
            
                return afterDeleting(s,i+1,e) || afterDeleting(s,i,e-1);
                
            }else{
                i++;
                e--;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        return checkpalindrome(s);
    }
};