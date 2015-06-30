#记着要排序
class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, num):
        length = len(num)
        num.sort()
        if length <= 1: return [num]
        pre = None
        res =[]
        for i  in range(length):
            if num[i] == pre: continue
            pre = num[i]
            for j in self.permuteUnique(num[0:i] + num[i+1:]):
                res.append([num[i]] + j)
        return res
