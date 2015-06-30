class Solution:
    # @param s, a string
    # @return an integer
    def minCut(self, s):
        n = len(s)
        isPal = [[False for j in xrange(n)] for i in xrange(n)]
        minPalNum = [i + 1 for i in xrange(n)]
        
        for j in xrange(n):
            for i in reversed(xrange(j + 1)):
                if s[i] == s[j] and (j - i <= 1 or isPal[i + 1][j - 1] == True):
                    isPal[i][j] = True
                    minPalNum[j] = min(minPalNum[i - 1] + 1, minPalNum[j]) if i > 0 else min(minPalNum[j], 1)
        return minPalNum[n - 1] - 1
        
