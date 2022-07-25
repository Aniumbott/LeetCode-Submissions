class Solution {
private:
    int n, m;
    int memoization(int i, int j, vector<vector<int>> &mat, vector<vector<int>>&dp){
        if(i >= n || j >= m) return 0;
        
        if(i == n-1 && j == m-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = 0, right = 0;
        
        if(!mat[i][j]){
            down = memoization(i+1, j, mat, dp);
            right = memoization(i, j+1, mat, dp);
         }
        return dp[i][j] = down+right;
    }
    
    int tabulation(){
        return 0;
    }
    
    int spaceOptimization(){
        return 0;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->n = obstacleGrid.size();
        this->m = obstacleGrid[0].size();
        vector<vector<int>> dp (n, vector<int> (m, -1));
        
        return (obstacleGrid[n-1][m-1] == 1)?0:memoization(0, 0, obstacleGrid, dp);
    }
};