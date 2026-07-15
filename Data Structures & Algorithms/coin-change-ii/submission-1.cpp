class Solution {
public:
    int slove(int i, int target, vector<int>& coins,vector<vector<int>>&dp) {
        if (target == 0) {
            return 1;
        }

        if (i == 0) {
            return (target % coins[0] == 0);
        }

        if(dp[i][target] != -1) return dp[i][target];

        int take = 0;
        if (coins[i] <= target) {
            take = slove(i, target - coins[i], coins,dp);
        }

        int notTake = slove(i - 1, target, coins,dp);

        return dp[i][target] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return slove(n - 1, amount, coins,dp);
    }
};