class Solution {
public:
    vector<string> ret;
    void dfs(int cntl, int cntr, int n, string s) {
        if (cntl + cntr == n*2) {
            ret.push_back(s);
            return;
        }
        if (cntl < n) {
            dfs(cntl+1, cntr, n, s+'(');
        }
        if (cntr < cntl && cntr < n) {
            dfs(cntl, cntr + 1, n, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(0, 0, n, s);
        return ret;
    }
};
