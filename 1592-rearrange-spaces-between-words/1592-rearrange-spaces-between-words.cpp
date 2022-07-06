class Solution {
public:
    string reorderSpaces(string text) {
        int ct=0;
        vector<string> v;
        for (int i=0; i<text.size(); i++){
            while(i<text.size() && text[i] == ' '){
                ct++;
                i++;
            }
            
            string tp="";
            
            while(i<text.size() && text[i] != ' '){
                tp+=text[i];
                i++;
            }
            
            i--;
            if(tp.size()) v.push_back(tp);
        }
        
        string ans = "";
        
        for(int i=0; i<v.size()-1; i++){
            ans += v[i];
            int j=ct/(v.size()-1);
            while(j--) ans += ' ';
        }
        
        ans += v[v.size()-1];
        int j=(v.size() > 1)?ct % (v.size()-1):ct;
        
        while(j--) ans += ' ';
        
        return ans;
    }
};