class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        sort(num.begin(),num.end());
        vector<int> vec(4);
        vector<vector<int> > ret;
        if (n < 4) return ret;
        int prei = num[0] - 1;
        int prej = num[1] - 1;
        for (int i = 0; i < n -3; ++i) {
            if (num[i] == prei) continue;
            prei = num[i];
            vec[0] = num[i];
            prej = num[i+1]-1;
            for (int j = i+1; j < n - 2; ++j) {
                if (num[j] == prej) continue;
                prej = num[j];
                vec[1] = num[j];
                int l = j+1, r = n-1;
                while (l < r) {
                    int sum = num[i] + num[j] + num[l] + num[r];
                    if (sum == target) {
                        vec[2] = num[l];
                        vec[3] = num[r];
                        ret.push_back(vec);
                        ++l,--r;
                        while (l < r && num[l] == num[l-1]&&num[r] == num[r+1]) {
                            ++l;
                            --r;
                        }
                    } else if (sum > target) {
                        --r;
                    } else {
                        ++l;
                    }
                }
            }
        }
        return ret;
    }
};
