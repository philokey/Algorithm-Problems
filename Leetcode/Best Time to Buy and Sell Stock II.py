class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if len(prices) == 0: return 0
        now = prices[0]
        ret = 0
        for i in prices:
            if i > now:
                ret += i - now
            now = i
        return ret
            
