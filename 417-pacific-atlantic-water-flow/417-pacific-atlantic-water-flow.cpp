class Solution {
private:
    int n, m;
    vector<vector<int>> mp, ans;
    
    void helper(vector<vector<int>>& heights, int x, int y, int pre, int preval){
         if (x < 0 || x >= n || y < 0 || y >= m || heights[x][y] < pre || (mp[x][y] & preval) == preval) 
            return;
        mp[x][y] |= preval;
        if (mp[x][y] == 3) ans.push_back({x, y});
        
        helper(heights, x + 1, y, heights[x][y], mp[x][y]); 
        helper(heights, x - 1, y, heights[x][y], mp[x][y]);
        
        helper(heights, x, y + 1, heights[x][y], mp[x][y]); 
        helper(heights, x, y - 1, heights[x][y], mp[x][y]);
     }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->n = heights.size();
        this->m = heights[0].size();
        
        mp.resize(n, vector<int> (m,0));
        
        for(int i=0; i<n; i++){
            helper(heights, i, 0, INT_MIN, 1);
            helper(heights, i, m - 1, INT_MIN, 2);
        }
        
        for(int i=0; i<m; i++){
            helper(heights, 0, i, INT_MIN, 1);
            helper(heights, n - 1, i, INT_MIN, 2);
        }
        
        return ans;
    }
};