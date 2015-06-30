class Solution {
public:
    vector<string> dp[1005],ret;
    void dfs(int pos,string str) {
        if (pos < 0) {
            ret.push_back(str);
            return;
        }
        int n = dp[pos].size();
        int len;
        for (int i = 0; i < n; ++i) {
            len = dp[pos][i].size();
            string tmp;
            if (str.length()) {
                tmp = dp[pos][i] + " " + str;
            } else {
                tmp = dp[pos][i];
            }
            dfs(pos-len,tmp);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
                if (i == 0 || dp[i-1].size()) {
                    int len = it->size();
                    if (i + len -1< n && s.substr(i,len) == *it) {
                        dp[i+len-1].push_back(*it);
                    }
                }
            }
        }
        string ss;
        dfs(n-1,ss);
        return ret;
    }
};
