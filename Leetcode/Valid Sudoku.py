class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        for row in board:
            dup = []
            for i in row:
                if i != '.':
                    if i not in dup: dup.append(i)
                    else: return False
        
        for j in range(9):
            dup = []
            for i in range(9):
                if board[i][j] != '.':
                    if board[i][j] not in dup: dup.append(board[i][j])
                    else: return False
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                dup = []
                for x in range(3):
                    for y in range(3):
                        tmp = board[i + x][j + y]
                        if tmp != '.':
                            if tmp not in dup: dup.append(tmp)
                            else: return False
        return True
