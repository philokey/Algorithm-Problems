class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        l, r = 0, len(A) - 1
        while l <= r:
            m = (l + r) / 2
            if A[m] == target: return m
            if A[m] > target: r = m - 1
            else : l = m + 1
        return l
