class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> mp;
        int ans = 0;
        for(auto c:allowed)
            mp[c] = true;
        
        for(auto s:words){
            for(auto c:s){
                if(!mp[c]){
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