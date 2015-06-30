#问清除是否可以不选任何数字

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        ret = 0
        sum = 0
        maxA = A[0]
        for i in A:
            maxA = max(maxA,i)
            if sum + i > 0:
                sum += i
                ret = max(ret,sum)
            else:
                sum = 0
        if ret == 0: ret = maxA 
        return ret
        
