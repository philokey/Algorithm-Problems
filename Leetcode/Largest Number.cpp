bool cmp(const int &a, const int &b){
    char sa[15], sb[15];
    int x = a/10, y = b/10;
    long long pa, pb;
    pa = pb = 10;
    while (x) {
        x /= 10;
        pa *= 10;
    }
    while (y) {
        y /= 10;
        pb *= 10;
    }
    long ab, ba;
    ab = a*pb + b;
    ba = b*pa + a;
    return ab > ba;
}
class Solution {
public:

    string toString(int a) {
        string ret = "";
        char ch;
        if (a == 0) ret = "0";
        while (a) {
            ch = a % 10 + '0';
            a /= 10;
            ret = ch + ret;
        }
        return ret;
    }
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp);
        string ret = "";
        for (int i = 0; i < num.size(); ++i) {
            if (ret == "" && num[i] == 0) continue;
            ret += toString(num[i]);
        }
        if (ret == "") ret = "0";
        return ret;
    }
};
