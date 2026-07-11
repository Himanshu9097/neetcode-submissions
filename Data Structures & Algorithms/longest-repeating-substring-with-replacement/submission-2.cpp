class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;
        unordered_map<char,int> mpp; // element , freq
        int l = 0, r = 0, maxFreq = 0;

        while(r < s.length()){
            mpp[s[r]]++;
            maxFreq = max(maxFreq , mpp[s[r]]);

            if((r-l+1) - maxFreq > k){
                mpp[s[l]]--;
                maxFreq = max(maxFreq , mpp[s[l]]);
                l++;
            }

            if(r-l+1-maxFreq <= k){
                maxi = max(maxi , r-l+1);
            }
            
            r++;
        }

        return maxi;
    }
};
