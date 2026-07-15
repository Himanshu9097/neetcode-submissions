class Solution {
public:
    int slove(int i , int j , vector<vector<int>>&mat,vector<vector<int>>&dp){
        int m = mat.size();
        int n = mat[0].size();

        if(i >= m || j >= n) return 0;
        if(mat[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        // move down
        int down = slove(i+1,j,mat,dp);

        // move right
        int right = slove(i,j+1,mat,dp);

        return dp[i][j] = down+right;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return slove(0,0,mat,dp);
    }
};