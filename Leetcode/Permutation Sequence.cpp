class Solution {
public:
    string getPermutation(int n, int k) {
        int cnt = 1;
        int num[15];
        for (int i = 1; i <= n; ++i) {
            num[i - 1] = i;
            cnt *= i;
        }
        --k;
        string ret = "";
        for (int i = 0; i < n; ++i) {
            cnt /= (n - i);
            int tmp = k / cnt;
            ret += num[tmp] + '0';
            for (int j = tmp; j < n - 1; ++j) {
                num[j] = num[j + 1];
            }
            k = k % cnt;
        }
        return ret;
    }
};
