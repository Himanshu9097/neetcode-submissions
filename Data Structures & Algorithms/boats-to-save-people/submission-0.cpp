class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        int low = 0 , high = n - 1;

        while(low <= high){
            int sum = nums[low] + nums[high];

            if(sum <= limit){
                low++;
                high--;
            }else{
                high--;
            }

            count++;
        }

        return count;
    }
};