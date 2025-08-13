class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        using ull = unsigned long long;
        vector<vector<ull>> dp(m+1, vector<ull>(n+1, 0));

        // Base case: empty t
        for (int i = 0; i <= m; i++)
            dp[i][n] = 1;

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return (int)dp[0][0]; // guaranteed to fit in 32-bit by problem statement
    }
};
