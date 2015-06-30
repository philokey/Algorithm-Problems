class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        numold = num[:]
        num.sort()
        i = 0
        n = len(num)
        j = n - 1 
        while (i < j):
            if num[i] + num[j] == target: break
            while num[i] + num[j] < target: i += 1
            while num[i] + num[j] > target: j -= 1
        for e in range(n):
            if numold[e] == num[i]:
                i = e
                break
        for e in reversed(range(n)):
            if numold[e] == num[j]:
                j = e
                break
        if i > j: i, j = j, i
        return (i+1,j+1)
