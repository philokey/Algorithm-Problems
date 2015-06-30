class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        N = n + m - 2
        M = m - 1
        ret = 1
        for i in range (M):
            ret = ret * (N - i) / (i + 1)
        return ret
