#神坑题，输入可能不合法，即结果为0
class Solution:
    # @param s, a string
    # @return an integer
    def numDecodings(self, s):
        n = len(s)
        if n == 0 or s[0] == '0': return 0
        if n == 1: return 1
        dp = [0 for i in range(n)]
        dp[0] = 1
        dp[1] = 2 if 10 <= int(s[0:2]) <= 26 and s[1] != '0' else 1
        if s[1] == '0' and s[0] > '2': return 0
        for i in range(2,n):
            if s[i] != '0':
                dp[i] = dp[i - 1]
            if 10 <= int(s[i - 1: i + 1]) <= 26:
                dp[i] += dp[i - 2]
            if dp[i] == 0: return 0
        return dp[n - 1]
