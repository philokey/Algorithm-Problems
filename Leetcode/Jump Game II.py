class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        n = len(A)
        if n == 1: return 0
        num = [n for i in range(n)]
        num[0] = 0
        ri = 0
        for i in range(n):
            if ri < i + A[i] :
                for j in range(ri + 1, min(i + A[i] + 1, n)) :
                    num[j] = num[i] + 1
                ri = i + A[i]
            if ri >= n - 1:
                return num[n - 1]
