class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        
        string ans = "";
        
        for(int i=0; i<knowledge.size(); i++)
            mp[knowledge[i][0]] = knowledge[i][1];
        
        for(int i=0; i<s.size(); i++){
            
            int j=i;
            while(j<s.size() && s[j]!='(') j++;
            
            // cout << i << "-" << j << endl;
            
            ans += s.substr(i, j-i);
            
            i=j+1;
            while(j<s.size() && s[j]!=')') j++;
            
            if(i < s.size())
                ans += (mp.find(s.substr(i, j-i)) != mp.end())?mp[s.substr(i, j-i)]:"?";
            
            else break;
            
            i=j;
            
            // cout << ans <<endl;
        }
        return ans;
    }
};