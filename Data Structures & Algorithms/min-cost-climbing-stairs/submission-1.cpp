class Solution {
public:
    int fn(int i , vector<int>&cost,vector<int>&dp){
        if(i >= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(fn(i+1,cost,dp) , fn(i+2,cost,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);

        return min(fn(0,cost,dp),fn(1,cost,dp));
    }
};
