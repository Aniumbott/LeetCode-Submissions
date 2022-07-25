class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pre(n,0);
        
        for(int j=0; j<n; j++) pre[j] = grid[0][j];
        
        for(int i=1; i<n; i++){
            vector<int> cur(n,0);
            for(int j=0; j<n; j++){
                int l=grid[i][j] ,m=grid[i][j] ,r=grid[i][j] ;
                m += pre[j];
                if(j-1 >= 0) l += pre[j-1];
                else l += 1e9;
                
                if(j+1 < n) r += pre[j+1];
                else r += 1e9;
                
                cur[j] = min(m, min(l,r));
            }
            pre=cur;
        }  
        int ans = INT_MAX;
        for(auto i:pre) ans = min(ans, i);
        return ans;
    }
};