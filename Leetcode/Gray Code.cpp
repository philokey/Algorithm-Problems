class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        if (n == 0) return ret;
        ret.push_back(1);
        int len = 1;
        int pow2 = 2;
        while (len < n) {
            for (int i = pow2 - 1; i >= 0; --i) {
                ret.push_back(pow2 + ret[i]);
            }
            len += 1;
            pow2 *= 2;
        }
        return ret;
    }
};
