class Solution {
public:
    bool isPalindrome(string s,int low,int high){
        while(low <= high){
            if(s[low] != s[high]){
                return false;
            }

            low++;high--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.length();
        int low = 0,high = n - 1;

        while(low <= high){
            if(s[low] == s[high]){
                low++;
                high--;
            }else{
                return isPalindrome(s,low+1,high)
                    || isPalindrome(s,low,high-1);
            }
        }

        return true;
    }
};