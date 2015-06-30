class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        rows = len(grid)
        cols = len(grid[0])
         
        dp = [[0 for j in xrange(cols)] for i in xrange(rows)]
        dp[0][0] = grid[0][0]
        for i in xrange(1, cols):
            dp[0][i] = dp[0][i - 1] + grid[0][i]
        for i in xrange(1, rows):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
         
        for i in xrange(1, rows):
            for j in xrange(1, cols):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        return dp[rows - 1][cols - 1]
