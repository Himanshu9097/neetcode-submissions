class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int max_water = INT_MIN;
        int curr_water = 0;
        int low = 0,high = n - 1;

        while(low < high){
            curr_water = min(nums[low],nums[high]) * (high - low);
            max_water = max(curr_water,max_water);

            if(nums[low] < nums[high]){
                low++;
            }else{
                high--;
            }
        }

        return max_water;
    }
};
