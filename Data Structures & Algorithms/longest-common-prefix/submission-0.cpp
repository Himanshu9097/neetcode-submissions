class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        string first = strs.front();
        string last = strs.back();

        int i = 0;
        string ans = "";

        while(i < first.length() && i < last.length()){
            if(first[i] == last[i]){
                ans+=first[i];
            }else{
                break;
            }
            i++;
        } 
        

        return ans;
    }
};