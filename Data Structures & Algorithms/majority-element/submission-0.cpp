class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        int maxi = INT_MIN;
        int ans;

        for(auto&pair:freq){
            if(pair.second > maxi){
                maxi = pair.second;
                ans = pair.first;
            }
        }

        return ans;

    }
};