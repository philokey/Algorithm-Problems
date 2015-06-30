class Solution:
    # @param A a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        n = len(A)
        if n <= 1: return n
        slow = 1
        cnt = 1
        for fast in xrange(1, n):
            if A[fast] == A[fast - 1]:
                cnt += 1
                if cnt <= 2:
                    A[slow] = A[fast]
                    slow += 1
            else:
                cnt = 1
                A[slow] = A[fast]
                slow += 1
        return slow
