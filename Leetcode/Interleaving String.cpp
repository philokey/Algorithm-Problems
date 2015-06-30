bool dp[2005][2005] ;
class Solution {
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if (n + m != s3.length()) return false;
        if (n == 0 || m == 0) {
            return s3 == s1 + s2;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i > 0 && s1[i - 1] == s3[i+j-1]) {
                    dp[i][j] |= dp[i-1][j];
                }
                if (j > 0 && s2[j - 1] == s3[i+j-1]) {
                    dp[i][j] |= dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
