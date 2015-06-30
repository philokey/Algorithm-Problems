class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        tail = 1
        n = len(A)
        if n <= 1: return n
        pre = A[0]
        i = 1
        while i < n:
            while i < n and pre == A[i]:
                i += 1
            if i < n:
                A[tail] = A[i]
                tail += 1
                pre = A[i]
        return tail
