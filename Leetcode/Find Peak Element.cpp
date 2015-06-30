class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0;
        int r = num.size() - 1;
        int n = num.size() - 1;
        int m;
        while (l <= r) {
            m = (l + r) / 2;
            if (m == l) {
                if (num[m] > num[r]) return m;
                else return r;
            }
            if (num[m] > num[m-1] && num[m] > num[m+1]) return m;
            if (num[m] > num[m - 1]) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};
