class Solution {
private:
    int cnt;
    int q[1005];
    bool vis[1005];
public:
void solve(int dep,  int n) {
        if (dep == n) {
            cnt += 1;
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
    int totalNQueens(int n) {
        cnt = 0;
        memset(vis, false, sizeof(vis));
        solve(0, n);
        return cnt;
    }
};
