class Solution {
public:
    
    bool helper(int p1, int p2, int p3, string s1, string s2, string s3, vector<vector<int>> &dp){
        if(p3 == s3.size()) return true;
        
        if(p1<s1.size() && p2<s2.size() && dp[p1][p2]!=-1) return dp[p1][p2];
        
        if(p1<s1.size() && p2<s2.size() && s3[p3] == s1[p1] && s3[p3] == s2[p2])
            return dp[p1][p2] = helper(p1+1, p2, p3+1, s1, s2, s3, dp) || helper(p1, p2+1, p3+1, s1, s2, s3, dp);
        
        if(s3[p3] == s1[p1])
            return helper(p1+1, p2, p3+1, s1, s2, s3, dp);
        if(s3[p3] == s2[p2])
            return helper(p1, p2+1, p3+1, s1, s2, s3, dp);
        
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(s3.size() != s1.size() + s2.size()) return false;
        
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        
        return helper(0, 0, 0, s1, s2, s3, dp);
    }
};