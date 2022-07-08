class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        string ans = "";
        
        for(int i=0; i<knowledge.size(); i++)
            mp[knowledge[i][0]] = knowledge[i][1];
        
        
        int i=0, n=s.size();
        while(i<n){            
            if(s[i] == '('){
                i++;
                string tp="";
                while(i<n && s[i] != ')'){
                    tp+=s[i];
                    i++;
                }
                if(mp.find(tp) == mp.end()) ans+="?";
                else ans += mp[tp];
            }
            else ans+=s[i];
            i++;
        }
        return ans;
    }
};