class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;

        for(int i = 0; i < s.length(); i++){
            unordered_map<char,int> mpp; // char , freq
            int maxFreq = 0;

            for(int j = i; j < s.length(); j++){
                mpp[s[j]]++;
                maxFreq = max(maxFreq,mpp[s[j]]);

                if((j-i+1) - maxFreq <= k){
                    maxi = max(maxi , j-i+1);
                }else{
                    break;
                }
            }

        }

        return maxi;
    }
};
