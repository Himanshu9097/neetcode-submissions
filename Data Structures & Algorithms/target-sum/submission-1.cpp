class Solution {
public:
    int slove(int i , int sum , int target , vector<int>&nums,
            vector<vector<int>>&dp,int offset){

        if(i == nums.size()){
            return (target == sum) ? 1 : 0;
        }

        if(dp[i][sum+offset] != -1){
            return dp[i][sum+offset];
        }

        return dp[i][sum+offset] = slove(i+1,sum+nums[i],target,nums,dp,offset)+
                            slove(i+1,sum-nums[i],target,nums,dp,offset);

    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for(int num : nums){
            total+=num;
        }

        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, -1));
        return slove(0,0,target,nums,dp,total);
    }
};
