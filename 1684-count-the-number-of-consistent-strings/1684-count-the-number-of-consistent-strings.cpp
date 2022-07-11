class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> mp(26, false);
        int ans = 0;
        for(auto c:allowed)
            mp[c-'a'] = true;
        
        for(auto s:words){
            for(auto c:s){
                if(!mp[c-'a']){
                    // cout << c << " ";
                    ans--;
                    break;
                }
            }
            ans++;
        }
        return ans;
    }
};