class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            int firstval = nums[i];
            int secondval = target - firstval;

            if(mp.find(secondval) != mp.end()){
                return {mp[secondval],i};
            }

            mp[firstval] = i;
        }
        return {};
    }
};
