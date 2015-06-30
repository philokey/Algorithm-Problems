class Solution {
public:
    vector<vector<int> > ret;
    void solve(int dep,int s,int n,int k,vector<int>vec) {
        if (dep == k) {
            ret.push_back(vec);
            return;
        }
        for (int i = s; i <= n; ++i) {
            vec.push_back(i);
            solve(dep+1,i+1,n,k,vec);
            vec.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int>vec;
        solve(0,1,n,k,vec);
        return ret;
    }
};
