class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        ret = [[]]
        pre = []
        preNum = -10**10
        S.sort()
        n = len(S)
        for i in S:
            oldSet = []
            if i == preNum: oldSet = pre
            else : oldSet = ret[:]
            preNum = i
            pre = []
            for j in oldSet:
                ret.append(j + [i])
                pre.append(j + [i])
        return ret
