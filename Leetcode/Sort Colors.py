class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        cnt = [0,0,0]
        for i in A:
            cnt[i] += 1
        pos = 0;
        for i in range(3):
            for j in range(cnt[i]):
                A[pos] = i
                pos += 1
        
