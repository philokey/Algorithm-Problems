class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        n = len(gas)
        if sum(gas) < sum(cost): return -1
        start = 0
        now = 0
        pos = 0
        for i in range(n):
            now += gas[i] - cost[i]
            if now < 0:
                now = 0
                pos = i+1
        return pos
