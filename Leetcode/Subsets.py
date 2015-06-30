class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        S.sort()
        ret = []
        n = len(S)
        for i in range(2**n):
            subset = []
            binary = bin(i)[2:]
            binary = '0' * (n - len(binary)) + binary
            for j in range(n):
                if binary[j] == '1':
                    subset.append(S[j])
            ret.append(subset)
        return ret
