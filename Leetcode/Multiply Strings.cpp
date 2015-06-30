class Solution {
public:
    string multiply(string num1, string num2) {
        int ans[2005] = {0};
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int l1 = num1.length();
        int l2 = num2.length();
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                ans[j+i] += (num1[i] - '0')*(num2[j] - '0');
            }
        }
        int pos = 0;
        while(pos <= l1 + l2 - 2 || ans[pos] > 9) {
            ans[pos + 1] += ans[pos] / 10;
            ans[pos] %= 10;
            ++pos;
        }
        string ret="";
        while(pos && ans[pos] == 0) --pos;
        for (int i = pos; i >= 0; --i) {
            ret += ans[i]+'0';
        }
        return ret;
    }
};
