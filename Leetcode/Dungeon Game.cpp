class Solution {
private:
    int dp[1005][1005];
public:
    bool judge(vector<vector<int> > &s, int hel) {
        int n = s.size();
        int m = s[0].size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    if (s[i][j] + hel <= 0) return false;
                    dp[i][j] = s[i][j] + hel;
                }
                if (i - 1 >= 0 && dp[i - 1][j] > 0) {
                    dp[i][j] = dp[i - 1][j] + s[i][j];
                }
                if (j - 1 >= 0 && dp[i][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + s[i][j]);
                }
            }
        }
        return dp[n - 1][m - 1] > 0;
    }
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int l = 1, r = 100000000, m;
        bool sta;
        while (l <= r) {
            m = (l + r) / 2;
            sta = judge(dungeon, m);
            if (sta == true) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
