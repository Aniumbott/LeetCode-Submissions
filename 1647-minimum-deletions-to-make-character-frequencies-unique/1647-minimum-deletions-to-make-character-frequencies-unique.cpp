class Solution {
public:
    int minDeletions(string s) {
        vector<int> mp(26,0);
        int ans=0;
        for(auto c:s) mp[c-'a'] ++;
        sort(mp.begin(), mp.end());
        for(int i=24; i>=0; i--){
            if(!mp[i]) break;
            if(mp[i] >= mp[i+1]){
                int p = mp[i];
                mp[i] = max(0, mp[i+1] - 1);
                ans += p - mp[i];
            }
        }
        return ans;
    }
};