class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> pre(grid[0].size(), 0);
        for(int i=0; i<grid.size(); i++){
            vector<int> tp(grid[0].size(), 0);
            for(int j=0; j<grid[0].size(); j++){
                if(i == 0 && j == 0) tp[j] = grid[i][j];
                else{
                    int right, down; 
                    right = down = grid[i][j];
                    if(j > 0) right += tp[j-1];
                    else right += 1e9;
                    if(i > 0) down += pre[j];
                    else down += 1e9;
                    tp[j] = min(right, down);
                }
            }
            pre = tp;
        }
        return pre[grid[0].size()-1];
    }
};