class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // num -> frequency

        // Count the frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        //Min heap to keep top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (const auto& val : freq) {
            minHeap.push({val.second, val.first}); // (frequency, number)
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the least frequent element
            }
        }

        
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
