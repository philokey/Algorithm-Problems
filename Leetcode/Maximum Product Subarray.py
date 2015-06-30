class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        n = len(A)
        ans = A[0]
        maxtmp = A[0]
        mintmp = A[0]
        for i in xrange(1, n):
            maxtmp, mintmp = max(maxtmp * A[i], mintmp * A[i], A[i]), min(maxtmp * A[i], mintmp * A[i], A[i])
            ans= max(ans, maxtmp)
        return ans
        