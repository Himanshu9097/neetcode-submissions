class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int sIdx = -1;
        int l = 0 , r = 0, count = 0;
        unordered_map<char,int> mpp; // char and freq

        for(char ch : t){
            mpp[ch]++;
        }


        while(r < s.size()){
            if(mpp[s[r]] > 0) count++;
            mpp[s[r]]--;

            while(count == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIdx = l;
                }

                mpp[s[l]]++;
                if(mpp[s[l]] > 0) count--;
                l++;
            }

            r++;
        }

        return (sIdx == -1) ? "" : s.substr(sIdx,minLen);
    }
};
