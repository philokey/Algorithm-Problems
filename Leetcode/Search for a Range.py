class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def getl(self,A,tar):
        l, r = 0, len(A) - 1
        while l <= r:
            m = (l + r) / 2
            if A[m] >= tar: r = m - 1
            else: l = m + 1
        if l > len(A) - 1 or A[l] != tar: return -1
        return l
    def getr(sefl, A, tar):
        l, r = 0, len(A) - 1
        while l <= r:
            m = (l + r) / 2
            if A[m] <= tar: l = m + 1
            else: r = m - 1
        if r < 0 or A[r] != tar: return -1
        return r
    def searchRange(self, A, target):
        return [self.getl(A,target), self.getr(A,target)]
