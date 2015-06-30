'''
桶排序,变形,每次交换保证有一个回到原位,所以只有n次交换
'''
class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        n = len(A)
        for i in xrange(n):
            while 0 < A[i] <= n and A[i] != i + 1:
                if A[i] == A[A[i] - 1]: break
                pos = A[i] - 1
                A[i], A[pos] = A[pos], A[i]
        for i in xrange(n):
            if A[i] != i + 1: return i + 1
        return n + 1
