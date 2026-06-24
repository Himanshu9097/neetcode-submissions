class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // count the nums[i] : freq

        for(auto num : nums){
            freq[num]++;
        }

        vector<pair<int,int>> freqlist;

        for(auto pair : freq){
            freqlist.push_back({pair.first,pair.second}); // num : freq
        }

        // sorting using bubble sort

        for(int i = 0;i<freqlist.size();i++){
            for(int j = i+1;j<freqlist.size();j++){
                if(freqlist[j].second > freqlist[i].second){
                    swap(freqlist[i],freqlist[j]);
                }
            }
        }

        vector<int> ans;

        for(int i = 0;i<k;i++){
            ans.push_back(freqlist[i].first);
        }

        return ans;
    }
};
