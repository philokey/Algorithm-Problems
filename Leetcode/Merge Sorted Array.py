class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        tail = n + m - 1
        n -= 1
        m -= 1
        while m >= 0 or n >= 0:
            if m >= 0 and n >= 0:
                if A[m] > B[n]:
                    A[tail] = A[m]
                    m -= 1
                else :
                    A[tail] = B[n]
                    n -= 1
            elif m >= 0:
                A[tail] = A[m]
                m -= 1
            else :
                A[tail] = B[n]
                n -= 1
            tail -= 1
            
