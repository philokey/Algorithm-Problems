class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        n = len(num)
        l, r = 0, n - 1
        while l < r:
            m = (l + r) / 2
            if num[m] >= num[l]:
                if num[l] > num[r]: l = m + 1
                else : return num[l]
            else: r = m 
            
        return num[l]
                