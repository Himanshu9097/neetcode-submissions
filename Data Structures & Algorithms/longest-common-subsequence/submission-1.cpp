class Solution {
public:
    vector<vector<int>> dp;
    int slove(int i,int j,int ans,string &text1,string &text2){
        if(i == text1.size() || j == text2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            dp[i][j] = 1+slove(i+1,j+1,ans,text1,text2);
        }else{
            int a = slove(i+1,j,ans,text1,text2);
            int b = slove(i,j+1,ans,text1,text2);

            dp[i][j] = max(a,b);
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.assign(n+1,vector<int>(m+1,-1));

        return slove(0,0,0,text1,text2);
    }
};
