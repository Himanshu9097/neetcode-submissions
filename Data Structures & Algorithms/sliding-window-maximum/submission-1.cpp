class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> res;

        int maxIdx = 0;

        // First window
        for (int i = 1; i < k; i++) {
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        res.push_back(nums[maxIdx]);

        int l = 1;
        int r = k;

        while (r < n) {

            // Previous maximum left the window
            if (maxIdx < l) {

                maxIdx = l;

                for (int i = l; i <= r; i++) {
                    if (nums[i] > nums[maxIdx])
                        maxIdx = i;
                }
            }
            // Maximum is still in the window
            else if (nums[r] >= nums[maxIdx]) {
                maxIdx = r;
            }

            res.push_back(nums[maxIdx]);

            l++;
            r++;
        }

        return res;
    }
};