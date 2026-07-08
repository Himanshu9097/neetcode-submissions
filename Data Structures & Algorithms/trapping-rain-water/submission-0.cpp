class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        int low = 0,high = n - 1;
        int leftmax = nums[low];
        int rightmax = nums[high];
        int water = 0;

        while(low < high){
            if(leftmax <= rightmax){
                low++;
                leftmax = max(nums[low],leftmax);
                int curr_water = leftmax - nums[low];
                water += curr_water;
            }else{
                high--;
                rightmax = max(nums[high],rightmax);
                int curr_water = rightmax - nums[high];
                water += curr_water;
            }
        }

        return water;
    }
};
