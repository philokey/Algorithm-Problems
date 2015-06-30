class Solution {
public:
    double get_pow(double x, int n) {
        if (n == 1) return x;
        if (n == 0) return 1;
        double tmp = get_pow(x, n / 2);
        if (n % 2) return tmp * tmp * x;
        else return tmp * tmp;
    }
    double pow(double x, int n) {
        double ret = get_pow(x, abs(n));
        if (n < 0) {
            ret = 1 / ret;
        }
        return ret;
    }
};
