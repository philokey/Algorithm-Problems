class Solution {
public:
    bool dp[1005] ={0};
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
                if (i == 0 || dp[i-1]) {
                    int len = it->size();
                    if (i + len - 1 < n && s.substr(i, len)==*it) {
                        dp[i+len-1] = 1;
                    }
                }
            }
        }
        return dp[n-1];
    }
};
