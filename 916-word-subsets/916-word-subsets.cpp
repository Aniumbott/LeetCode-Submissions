class Solution {
private:
    void helper(string s, int a[26]){
        for(auto c:s) a[c-'a']++;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        int mp[26] = {0};
        for(auto &w:words2){
            int a[26]={0};
            helper(w, a);
            for(int i=0; i<26; i++){
                mp[i] = max(mp[i], a[i]);
            }
        }
        
        for(auto &w:words1){
            int tmp[26] = {0};
            helper(w, tmp);
            int i;
            for(i=0; i<26; i++) if(tmp[i] < mp[i]) break;
            if(i == 26) ans.push_back(w);
        }
        
        return ans;
    }
};