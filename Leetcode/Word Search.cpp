class Solution:
    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean
    def exist(self, board, word):
        self.dir = [[0,1],[0,-1],[1,0],[-1,0]]
        self.n ,self.m = len(board), len(board[0])
        flag = False
        for i in range(self.n):
            for j in range(self.m):
                if flag == True: return True
                if board[i][j] == word[0]:
                    ch, board[i][j]= board[i][j], '#'
                    flag = self.dfs(board,i,j,word[1:])
                    board[i][j] = ch
        return flag
    
    def dfs(self,board,x,y,word):
        if len(word) == 0: return True
        for d in self.dir:
            dx = x + d[0]
            dy = y + d[1]
            if dx >= 0 and dx < self.n and dy >= 0 and dy < self.m and board[dx][dy] == word[0]:
                ch, board[dx][dy] = board[dx][dy], '#'
                if self.dfs(board,dx,dy,word[1:]): return True
                board[dx][dy] = ch
        return False
