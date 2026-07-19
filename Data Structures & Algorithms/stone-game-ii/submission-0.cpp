class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int m, vector<int>& piles) {
        if (i >= n)
            return 0;

        if (2 * m >= n - i)
            return suffix[i];

        if (dp[i][m] != -1)
            return dp[i][m];

        int ans = 0;

        for (int x = 1; x <= 2 * m; x++) {
            ans = max(ans,
                      suffix[i] - solve(i + x, max(m, x), piles));
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return solve(0, 1, piles);
    }
};