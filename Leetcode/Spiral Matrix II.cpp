int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
class Solution {
private:
    vector<vector<int> > ret;
    bool vis[1005][1005];
public:
    vector<vector<int> > generateMatrix(int n) {
        memset(vis, 0, sizeof(vis));
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            ret.push_back(vec);
        }
        int N = n*n;
        int x = 0, y = -1;
        int nx, ny;
        int dir = 0;
        for (int i = 1; i <= N; ++i) {
            nx = x + dx[dir];
            ny = y + dy[dir];
            while (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny] == true) {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            vis[nx][ny] = true;
            ret[nx][ny] = i;
            x = nx;
            y = ny;
        }
        return ret;
    }
};
