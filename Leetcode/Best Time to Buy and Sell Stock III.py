class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        n = len(prices)
        if n == 0: return 0
        dp1 = [0 for i in range(n)]
        dp2 = [0 for i in range(n)]
        val = prices[0]
        mx = 0
        for i in range(n):
            mx = max(mx, prices[i] - val)
            val = min(prices[i], val)
            dp1[i] = mx
        val = prices[n - 1]
        mx = 0
        for i in reversed(range(n)):
            mx = max(mx, val - prices[i])
            val = max(val, prices[i])
            dp2[i] = mx
        ret = 0
        for i in range(n):
            ret = max(ret,dp1[i] + dp2[i])
        return ret
