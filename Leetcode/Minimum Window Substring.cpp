class Solution {
public:
    string minWindow(string S, string T) {
        int lens = S.size(), lent = T.size();
        int srcCnt[256] = {0};
        int foundCnt[256] = {0};
        for(int i = 0; i < lent; i++) {
            srcCnt[T[i]]++;
        }
        int hasFound = 0;
        int winStart = -1, winEnd = lens;
        for(int i = 0, start = 0; i < lens; i++) {
            if(srcCnt[S[i]] != 0) {
                foundCnt[S[i]]++;
                if(foundCnt[S[i]] <= srcCnt[S[i]])hasFound++;
                if(hasFound == lent) {
                    while(srcCnt[S[start]] == 0 || foundCnt[S[start]] > srcCnt[S[start]]) {
                        if(srcCnt[S[start]] != 0) {
                            foundCnt[S[start]]--;
                        }
                        start++;
                    }
                    if(winEnd - winStart > i - start) {
                        winStart = start;
                        winEnd = i;
                    }
                    foundCnt[S[start]]--;
                    start++;
                    hasFound--;
                }
            }
        }
        return winStart != -1 ? S.substr(winStart, winEnd - winStart +1) : "";
    }
};
