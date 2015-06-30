class Solution {
public:
    vector<int> getRow(int rowIndex) {
        bool now,pre;
        int **ret = new int*[2];
        ret[0] = new int[rowIndex+1];
        ret[1] = new int[rowIndex+1];
        now = 0;
        pre = 1;
        ret[now][0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            swap(now,pre);
            ret[now][0] = ret[now][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[now][j] = ret[pre][j-1] + ret[pre][j];
            }
        }
        vector<int> ans;
        for (int i = 0; i <= rowIndex; ++i) {
            ans.push_back(ret[now][i]);
        }
        return ans;
    }
};
