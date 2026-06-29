class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq; // {ele, freq}

        for(int num : nums){
            freq[num]++;
        }

        //Max- Heap : {freq, ele}
        priority_queue<pair<int, int>> pq;

        for(auto&pair:freq){
            pq.push({pair.second,pair.first});
        }

        vector<int> ans;

        for(int i = 0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};
