class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        ls = s.split()
        if len(ls) == 0: return 0
        return len(ls[-1])
