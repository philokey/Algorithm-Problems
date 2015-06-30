class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        lmax = [0 for i in range(len(A))]
        tmp = 0
        for i in range(len(A)):
            tmp = max(tmp, A[i])
            lmax[i] = tmp
        ret = 0
        rmax = 0
        for i in reversed(range(len(A))):
            rmax = max(rmax, A[i])
            if lmax[i] > A[i]:
                ret += min(lmax[i], rmax) - A[i]
        return ret
