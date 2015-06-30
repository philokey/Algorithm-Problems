class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        n = len(A)
        reach = 0
        for i in range(n):
            if reach < i: break
            if reach >= n - 1: break
            reach = max(reach, i + A[i])
        if reach >= n - 1: return True
        else: return False
