class Solution {
private:
    void helper(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == '2' || grid[i][j] == '0') return;
        grid[i][j] = '2';
        helper(grid, i+1, j);
        helper(grid, i, j+1);
        helper(grid, i, j-1);
        helper(grid, i-1, j);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    helper(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};