class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        n = len(ratings)
        candy = [1 for i in range(n)]
        for i in range(n - 1):
            if ratings[i+1] > ratings[i] and candy[i+1] <= candy[i]:
                candy[i+1] = candy[i] + 1
        for i in reversed(range(1, n)):
            if ratings[i] < ratings[i - 1] and candy[i] >= candy[i - 1]:
                candy[i - 1] = candy[i] + 1
        return sum(candy)
