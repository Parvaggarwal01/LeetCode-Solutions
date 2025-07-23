class Solution {
public:
    int minPath(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(i == 0 && j == 0){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = minPath(grid, i-1, j, dp);
        int left = minPath(grid, i, j-1, dp);
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPath2(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m){
            return INT_MAX;
        }
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = minPath2(grid, i, j+1, dp);
        int down = minPath2(grid, i+1, j, dp);
        return dp[i][j] = grid[i][j] + min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minPath(grid, n-1, m-1, dp);
    }
};