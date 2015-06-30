class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        n = len(strs)
        if n == 0: return ''
        if n == 1: return strs[0]
        length = [len(i) for i in strs]
        ret = 0
        for i in xrange(min(length)):
            now = strs[0][i]
            for j in xrange(n):
                if strs[j][i] != now: return strs[0][:i]
            ret += 1
        return strs[0][:ret]