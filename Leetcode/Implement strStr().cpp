class Solution {
public:
    char *mst , *text;
    int *nnext;
    int txtlen, mslen;
    void findnext() {
         nnext[0] = -1;
        for (int j = -1, i = 1;mst[i]; i++) {
            while (j > -1 &&mst[j+1] != mst[i]) j = nnext[j];
            if (mst[j+1] == mst[i]) j++;
            nnext[i] = j;
        }
    }
    int kmp() {
        findnext();
        int j = -1;
        for (int i = 0; i < txtlen; ++i) {
            while (j > -1 && mst[j+1]!=text[i]) {
                j = nnext[j];
            }
            if (mst[j+1] == text[i]) ++j;
            if (j == mslen - 1) {
                return i;
            }
            
        }
        return -1;
    }
    
    char *strStr(char *haystack, char *needle) {
        char *ret;
        ret = NULL;
        mst = needle;
        text = haystack;
        txtlen = strlen(haystack);
        mslen = strlen(needle);
        if (mslen == 0) {
            return haystack;
        }
        nnext = new int[txtlen+15];
        int res = kmp();
        if (res == -1) return ret;
        res = res - mslen + 1;
        ret = haystack + res;
        return ret;
    }
};
