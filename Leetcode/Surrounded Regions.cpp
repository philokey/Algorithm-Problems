class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void solve(vector<vector<char> > &board) {
        queue<pair<int, int> > q;
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = '$';
                q.push(make_pair(0, i));
            }
            if (board[n-1][i] == 'O') {
                board[n-1][i] = '$';
                q.push(make_pair(n-1, i));
            }
        }
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '$';
                q.push(make_pair(i, 0));
            }
            if (board[i][m-1] == 'O') {
                board[i][m-1] = '$';
                q.push(make_pair(i, m-1));
            }
        }
        while (!q.empty()) {
            pair<int, int> pa = q.front();
            q.pop();
            int x = pa.first, y = pa.second;
            for (int k = 0; k < 4; ++k) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && board[xx][yy] == 'O') {
                    board[xx][yy] = '$';
                    q.push(make_pair(xx, yy));
                }
            }

        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
};
