class Solution {
public:
    int slove(int i , int sum , int target , vector<int>&nums){
        int count = 0;
        if(i == nums.size()){
            return (target == sum) ? 1 : 0;
        }

        count += slove(i+1,sum+nums[i],target,nums);
        count += slove(i+1,sum-nums[i],target,nums);

        return count;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        return slove(0,0,target,nums);
    }
};
