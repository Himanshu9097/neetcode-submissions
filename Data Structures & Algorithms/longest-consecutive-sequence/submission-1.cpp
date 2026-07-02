class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        int maxcount = 0;

        for(auto& it:freq){
            int num = it.first;
            if(freq.find(num-1) == freq.end()){
                int target = num+1;
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
