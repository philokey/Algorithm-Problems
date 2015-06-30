int maxbit(int data[], int n) {
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        int tmp = data[i];
        int bit = 0;
        while(tmp) {
            tmp /= 10;
            bit += 1;
        }
        ret = max(ret, bit);
    }
    return ret;
}
void radixsort(int data[], int n) {
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int cnt[10];
    for (int i = 1, radix = 1; i <= d; ++i, radix*=10) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < n; j++) {
            int k = (data[j] / radix) % 10;
            ++cnt[k];
        }
        for (int j = 1; j < 10; ++j) {
            cnt[j] += cnt[j - 1];
        }
        for (int j = n - 1; j >= 0; --j) {
            int k = (data[j] / radix) % 10;
            tmp[cnt[k] - 1] = data[j];
            --cnt[k];
        }
        memcpy(data, tmp, sizeof(int)*n);
    }
    delete []tmp;
}
class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        
        int *data = new int[n];
        for (int i = 0; i < n; ++i) {
            data[i] = num[i];
        }
        radixsort(data, n);
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            ret = max(ret, abs(data[i] - data[i-1]));
        }
        return ret;
    }
};
