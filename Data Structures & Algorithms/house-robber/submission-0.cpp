class Solution {
public:
    int slove(int i , vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int taken = nums[i] + slove(i+2,nums,dp);
        int notaken = slove(i+1,nums,dp);

        return dp[i] = max(taken , notaken);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1,-1);

        return slove(0,nums,dp);
    }
};
