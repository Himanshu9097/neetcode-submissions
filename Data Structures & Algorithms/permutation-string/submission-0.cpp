class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int l = 0, r = 0;
        int count = 0;
        vector<int> hash(26, 0);

        for(char c : s1)
            hash[c - 'a']++;

        while(r < s2.length()) {

            if(hash[s2[r] - 'a'] > 0)
                count++;

            hash[s2[r] - 'a']--;

            // Keep window size equal to s1.length()
            if(r - l + 1 > s1.length()) {

                hash[s2[l] - 'a']++;

                if(hash[s2[l] - 'a'] > 0)
                    count--;

                l++;
            }

            if(count == s1.length())
                return true;

            r++;
        }

        return false;
    }
};