class Solution {
public:
    char str[3005];
    int n,p[3005];
    void manacher() {
        int mx = 0 , id;
        for(int i = 1; i <= n; ++i) {
            if(mx > i) p[i] = min(p[2*id-i],mx-i);
            else p[i]=1;
            while(str[i+p[i]]==str[i-p[i]]) p[i]++;
            if(p[i]+i>mx) {
                mx=p[i]+i;
                id = i;
            }
        }

    }
    string longestPalindrome(string s) {
        int len = s.length();
        n = len*2+1;
        str[0]='+';
        for(int i = 0; i <= len; i++)
        {
            str[2*i+1]='#';
            str[2*i+2]=s[i];
        }
        manacher();
        int ans = 0,cent;
        for(int i = 1; i < n; ++i) {
            if (p[i] > ans) {
                ans = p[i];
                cent = i;
            }
        }
       
        return s.substr((cent  - ans)/2, ans-1);
    }
};
