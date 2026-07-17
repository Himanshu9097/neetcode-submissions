class Solution {
public:
    int slove(int i, int j , vector<int>&piles,vector<vector<int>>&dp){
        if(i == j) return piles[i];

        if(dp[i][j] != -1) return dp[i][j];

        int left = piles[i] - slove(i+1,j,piles,dp);
        int right = piles[j] - slove(i,j-1,piles,dp);

        return dp[i][j] = max(left,right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return slove(0,n-1,piles,dp) > 0;
    }
};