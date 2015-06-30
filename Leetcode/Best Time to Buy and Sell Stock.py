class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if len(prices) == 0: return 0
        mi = prices[0]
        ret = 0
        for i in prices:
            ret = max(ret, i - mi)
            mi = min(i,mi)
        return ret
