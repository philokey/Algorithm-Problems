class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def searchMatrix(self, matrix, target):
        if len(matrix) == 0: return False
        n, m = len(matrix), len(matrix[0])
        x = 0
        y = m - 1
        while x < n and y >= 0:
            if matrix[x][y] == target: return True
            if matrix[x][y] > target: y -= 1
            else: x += 1
        return False
