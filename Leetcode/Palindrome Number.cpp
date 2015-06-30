class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int tmp = x, re = 0;
        while (tmp) {
            re = re * 10 + tmp % 10;
            tmp /= 10;
        }
        return x == re;
    }
};
