class Solution {
public:
    int memoize(int i, int j, int n, vector<vector<int>>& t, vector<vector<int>>& mp) {
        if (i == n) return 0;
        if (mp[i][j] != -1) return mp[i][j];
        
        int lower_left = t[i][j] + memoize(i + 1, j, n, t, mp);
        int lower_right = t[i][j] + memoize(i + 1, j + 1, n, t, mp);
        mp[i][j] = min(lower_left, lower_right);
        
        return mp[i][j];
    }
    
    int tabulate(vector<vector<int>> mat){
        int dp[mat.size()][mat.size()], d, dg, n = mat.size();
        for(int j=0; j<n; j++) dp[n-1][j] = mat[n-1][j];
        for(int i = n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                d = mat[i][j] + dp[i+1][j];
                dg = mat[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
    
    int spaceOptimized(vector<vector<int>> mat){
        int n = mat.size();
        vector<int> pre(n, 0);
        for(int j=0; j<n; j++) pre[j] = mat[n-1][j];
        for(int i = n-2; i>=0; i--){
            vector<int> cur(n, 0);
            for(int j=i; j>=0; j--){
                int d = mat[i][j] + pre[j];
                int dg = mat[i][j] + pre[j+1];
                cur[j] = min(d, dg);
            }
            pre = cur;
        }
        return pre[0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> mp(n, vector<int>(n, -1));
        // return memoize(0, 0, n, triangle, mp);
        // return tabulate(triangle);
        return spaceOptimized(triangle);
    }
};