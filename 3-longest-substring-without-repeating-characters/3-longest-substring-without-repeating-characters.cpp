class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(300,-1);
        int pos, ans;
        ans = 0;
        pos = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int ch = s[i];
            pos = max(pos, mp[ch]);   
            ans = max(ans, i - pos);
            mp[ch] = i;
        }

        return ans;
    }
};