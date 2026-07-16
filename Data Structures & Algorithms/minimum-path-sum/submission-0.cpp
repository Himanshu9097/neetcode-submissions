class Solution {
public:
    int slove(int i , int j , vector<vector<int>>&grid,
                vector<vector<int>>&dp){
        
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return INT_MAX;
        if(i == m-1 && j == n-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        // move down
        int down = slove(i+1,j,grid,dp);
        
        // move right
        int right = slove(i,j+1,grid,dp);

        return dp[i][j] = grid[i][j] + min(down,right);
        
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return slove(0,0,grid,dp);
    }
};