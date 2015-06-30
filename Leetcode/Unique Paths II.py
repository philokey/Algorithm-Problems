class Solution:
	# @param obstacleGrid, a list of lists of integers
	# @return an integer
	def uniquePathsWithObstacles(self, obstacleGrid):
		n, m = len(obstacleGrid), len(obstacleGrid[0])
		dp =[[0 for j in range(m)] for i in range(n)]
		for i in range(n):
			if obstacleGrid[i][0] == 1: break
			dp[i][0] = 1
		for i in range(m):
			if obstacleGrid[0][i] == 1: break
			dp[0][i] = 1
		for i in range(1,n):
			for j in range(1,m):
				if obstacleGrid[i][j] == 0:
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
		return dp[n - 1][m - 1]

