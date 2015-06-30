class Solution {
private:
    long long p[100005];
    long long ha[100005];
    int n;
    vector<string> ret;
    map<long long, bool> mp;
public:
    long long calHa(int l, int r) {
        if (!l) return ha[r];
        return ha[r] - ha[l - 1] * p[r - l + 1];
    }
    vector<string> findRepeatedDnaSequences(string s) {
        n = s.length();
        if (n < 10) {
            return ret;
        }
        p[0] = 1;
        ha[0] = s[0];
        for (int i = 1; i < n; ++i) {
            p[i] = p[i - 1] * 131;
            ha[i] = ha[i - 1] * 131 + s[i];
        }
        long long hkey;
        string tmp;
        for (int i = 9; i < n; ++i) {
            hkey = calHa(i - 9, i);
            if (mp.find(hkey) != mp.end()) {
                if (mp[hkey] == false) {
                    mp[hkey] = true;
                    ret.push_back(s.substr(i - 9, 10)); 
                }
            } else {
                mp[hkey] = false;
            }
        }
        return ret;
    }
};
