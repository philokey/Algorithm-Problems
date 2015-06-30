class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        n = len(triangle)
        dp = [0 for i in range(n)]
        for row in triangle:
            pre = dp[:]
            for i in range(len(row)):
                if i == 0:
                    dp[i] = pre[i] + row[i]
                elif i == len(row) - 1:
                    dp[i] = pre[i - 1] + row[i]
                else :
                    dp[i] = min(pre[i], pre[i - 1]) + row[i]
        return min(dp)
            
