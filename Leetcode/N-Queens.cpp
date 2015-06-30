class Solution {
private:
    vector<vector<string> > ret;
    bool vis[1005];
    int q[1005];
public:
    void solve(int dep,  int n) {
        if (dep == n) {
            string line;
            vector<string> vec;
            for (int i = 0; i < n; ++i) {
                line += '.';
            }
            for (int i = 0; i < n; ++i) {
                line[q[i]] = 'Q';
                vec.push_back(line);
                line[q[i]] = '.';
            }
            ret.push_back(vec);
            return;
        }
        for (int i = 0; i < n; ++i) {
            bool flag = true;
            if (vis[i] == false) {
                for (int j = 0; j < dep; ++j) {
                    if (abs(dep - j) == abs(i - q[j])) {
                        flag = false;
                        break;
                    }
                }
                if (flag == false) continue;
                vis[i] = true;
                q[dep] = i;
                solve(dep + 1, n);
                vis[i] = false;
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        memset(vis, false, sizeof(vis));
        solve(0, n);
        return ret;
    }
};
