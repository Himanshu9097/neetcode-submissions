class Solution {
public:
    int slove(int i,int sum , vector<int>&nums,
            vector<vector<int>>&dp,int offset){

        if(i == nums.size()){
            return abs(sum);
        }

        if(dp[i][sum+offset] != -1) return dp[i][sum+offset];

        int right = slove(i+1,sum+nums[i],nums,dp,offset);
        int left = slove(i+1,sum-nums[i],nums,dp,offset);

        return dp[i][sum+offset] = min(right,left);
    }

    int lastStoneWeightII(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int num : nums){
            total+=num;
        }

        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, -1));

        return slove(0,0,nums,dp,total);
    }
};