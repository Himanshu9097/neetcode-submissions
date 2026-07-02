class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        int maxcount = 0;

        for(int i = 0; i < nums.size(); i++){
            if(freq.find(nums[i]-1) == freq.end()){
                int target = nums[i]+1;
                int count = 1;

                while(freq.find(target) != freq.end()){
                    count++;
                    target++;
                }

                maxcount = max(maxcount,count);
            }
        }

        return maxcount;
    }
};
