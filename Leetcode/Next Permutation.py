class Solution:
    # @param num, a list of integer
    # @return a list of integer
    def nextPermutation(self, num):
        lenNum = len(num)
        partitionIndex = -1
        for i in reversed(range(lenNum - 1)):
            if num[i] < num[i + 1]:
                partitionIndex = i
                break
        if partitionIndex != -1:
            for i in reversed(range(lenNum)):
                if num[i] > num[partitionIndex]:
                    num[i], num[partitionIndex] = num[partitionIndex], num[i]
                    break
        i = partitionIndex + 1
        j = lenNum - 1
        while i < j:
            num[i], num[j] = num[j], num[i]
            i += 1
            j -= 1
        return num
        
