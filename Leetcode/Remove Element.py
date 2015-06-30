class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        n = len(A)
        tail = n - 1
        i = 0
        while i <= tail:
            if A[i] == elem:
                A[i] = A[tail]
                tail -= 1
                i -= 1
            i += 1
        return tail + 1
        
