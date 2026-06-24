class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        long long prod = 1;


        // prefixProduct 
        for(int i = 0; i < n; i++){
            prod*=nums[i];
            prefix[i] = prod;
        }

        prod = 1;
        // suffix product
        for(int i = n-1; i >= 0; i--){
            prod*=nums[i];
            suffix[i] = prod;
        }

        vector<int> result(n);

        for(int i = 0; i < n; i++){
            if(i == 0) result[i] = suffix[i+1];
            else if (i == n - 1) result[i] = prefix[i-1];
            else result[i] = prefix[i-1] * suffix[i+1];
        }

        return result;

    }
};
