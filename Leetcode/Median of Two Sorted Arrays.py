class Solution:
    # @return a float
    def getMid(self, A, B, k):
        n = len(A)
        m = len(B)
        if n > m: return self.getMid(B, A, k)
        if n == 0: return B[k - 1]
        if k == 1: return min(A[0], B[0])
        pa = min(n, k / 2)
        pb = k - pa
        if A[pa - 1] < B[pb - 1]:
            return self.getMid(A[pa:], B, k - pa)
        else :
            return self.getMid(A, B[pb:], k - pb)
        
    def findMedianSortedArrays(self, A, B):
        n , m= len(A), len(B)
        if (n + m) % 2 == 1:
            return self.getMid(A, B, (n + m) / 2 + 1)
        else :
            return 0.5 *(self.getMid(A, B, (n + m) / 2) + self.getMid(A, B, (n + m) / 2 + 1))
