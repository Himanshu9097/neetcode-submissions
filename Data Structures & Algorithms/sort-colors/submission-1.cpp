class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int c0 = 0,c1 = 0,c2 = 0;

        for(auto num : nums){
            if(num == 0) c0++;
            if(num == 1) c1++;
            if(num == 2) c2++;
        }

        int idx = 0;

        for(int i = 0; i<c0; i++){
            nums[idx++] = 0;
        }
        for(int i = 0; i<c1; i++){
            nums[idx++] = 1;
        }
        for(int i = 0; i<c2; i++){
            nums[idx++] = 2;
        }

    }
};