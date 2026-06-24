class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp; // num , index

        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){
                return true;
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};