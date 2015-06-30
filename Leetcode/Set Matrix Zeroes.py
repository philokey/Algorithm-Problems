class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        if len(matrix) == 0: return;
        n = len(matrix)
        m = len(matrix[0])
        row = [False for i in range(n)]
        col = [False for i in range(m)]
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True
        
        for i in range(n):
            for j in range(m):
                if row[i] or col[j]:
                    matrix[i][j] = 0
                
        
        
