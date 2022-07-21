class Solution {
public:
    int dfs(int i, int j, int n, vector<vector<int>>& t, vector<vector<int>>& mp) {
        if (i == n) return 0;
        if (mp[i][j] != -1) return mp[i][j];
        
        int lower_left = t[i][j] + dfs(i + 1, j, n, t, mp);
        int lower_right = t[i][j] + dfs(i + 1, j + 1, n, t, mp);
        mp[i][j] = min(lower_left, lower_right);
        
        return mp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> mp(n, vector<int>(n, -1));
        return dfs(0, 0, n, triangle, mp);
    }
};