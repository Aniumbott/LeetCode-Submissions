class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0, fresh=0, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        while(fresh){
            
            int tp = fresh;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == 1){
                        if((i < m-1 && grid[i+1][j] == 2) ||
                           (j < n-1 && grid[i][j+1] == 2) ||
                           (i > 0 && grid[i-1][j] == 2) ||
                           (j > 0 && grid[i][j-1] == 2))
                        {
                            grid[i][j] = -1;
                            tp--;
                        }
                    }
                }
            }
              
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == -1) grid[i][j] = 2;
                    // cout << grid[i][j] << " ";
                }
                // cout << endl;
            }
            // cout << endl;
            
            if(tp == fresh) return -1;
            fresh = tp;
            time++;
        }
        return time;
    }
};