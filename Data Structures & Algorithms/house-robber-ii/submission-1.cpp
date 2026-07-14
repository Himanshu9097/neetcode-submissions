class Solution {
public:
    int slove(int idx , int end ,vector<int>&nums,vector<int>&dp){
        if(idx > end) return 0;

        // value already present at dp array
        if(dp[idx] != -1) return dp[idx];

        // take the current element
        int taken = nums[idx] + slove(idx+2,end,nums,dp);

        // not taken 
        int notaken = slove(idx+1,end,nums,dp);

        dp[idx] = max(taken,notaken);

        return dp[idx];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);

        int case1 = slove(0,n-2,nums,dp1);
        int case2 = slove(1,n-1,nums,dp2);

        return max(case1, case2);
    }
};
